#include <iostream>
#include <iomanip>
using namespace std;
enum Color {RED, BLACK}; 
  int count=0;
  //int c=0;
  
struct Node 
{ 
    int data; 
    bool color; 
    Node *left, *right, *parent;  
    Node(int data) 
    { 
       this->data = data; 
       left = right = parent = NULL; 
       this->color = RED; 
    } 
}; 
Node* bhead;
Node * ahead;
/**
*inserting node in bst
*/
Node* BSTInsert(Node* root, Node *ptr) 
{ 
    if (root == NULL) 
       return ptr; 
    if (ptr->data < root->data) 
    { 
        root->left  = BSTInsert(root->left, ptr); 
        root->left->parent = root; 
    } 
    else if (ptr->data > root->data) 
    { 
        root->right = BSTInsert(root->right, ptr); 
        root->right->parent = root; 
    } 
    count++;
    return root; 
} 
/**
*inrder traversal of bst
*/
void inorder(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    inorder(root->left); 
    cout << root->data << "  "; 
    inorder(root->right); 
} 
/**
*creating rbtree class
*/
class RBTree 
{ 
private: 
    Node *root; 
protected: 
    void rotateLeft(Node *&, Node *&); 
    void rotateRight(Node *&, Node *&); 
    void fixViolation(Node *&, Node *&); 
public:  
    RBTree() { root = NULL; } 
    void insert(const int &n); 
    void paths();
    void Prints();
};
/**
*left rotate function
*/
void RBTree::rotateLeft(Node *&root, Node *&pt) 
{ 
    Node *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
} 
  
void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
    Node *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 
/**
*color of node
*/
void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
    Node *parent_pt = NULL; 
    Node *grand_parent_pt = NULL; 
  
    while ((pt != root) && (pt->color != BLACK) && 
           (pt->parent->color == RED)) 
    { parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
        if (parent_pt == grand_parent_pt->left) 
        {
            Node *uncle_pt = grand_parent_pt->right; 
            if (uncle_pt != NULL && uncle_pt->color == RED) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
                rotateRight(root, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
  
        else
        { 
            Node *uncle_pt = grand_parent_pt->left; 
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
                rotateLeft(root, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = BLACK; 
} 
/**
*inserting node in rbtree
*/
void RBTree::insert(const int &data) 
{ 
    Node *pt = new Node(data); 
    root = BSTInsert(root, pt); 
    fixViolation(root, pt); 
} 
/**
*storing bst
*/
 Node* sortedArrayToBST(int a[],  int s, int l)  
{
    if (s > l)  
    return NULL;  
    int mid = (s+l+1)/2;  
    Node *root = new Node(a[mid]);  
    root->left = sortedArrayToBST(a,s,mid - 1);  
    root->right = sortedArrayToBST(a,mid + 1,l);  
   return root;  
}  
/**
*insert in bst
*/
 void insertbst(const int &data) 
{ 
    Node *pt = new Node(data); 
    bhead = BSTInsert(bhead, pt); 
} 
/**
*printing the array
*/
void printArray(int ints[], int len)  
{  
    int i;  
    for (i = 0; i < len; i++)  
    {  
       if(i!=len-1) cout << ints[i] << "->"; else cout<<ints[i]; 
    }  
    cout<<endl;  
} 
/**
*printing paths recursively
*/ 
void printPathsRecur(Node* node, int path[], int pathLen)  
{  
    if (node == NULL)  
        return;  
    path[pathLen] = node->data;  
    pathLen++;  
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
        printPathsRecur(node->left, path, pathLen);  
        printPathsRecur(node->right, path, pathLen);  
    }  
}  
/**
*printing paths for avl
*/
void printPaths(Node* node)  
{  
    int path[1000];  
    printPathsRecur(node, path, 0);  
    if (node->left != NULL) 
	 printPaths(node->left); 
    if (node->right != NULL) 
	printPaths(node->right);  
} 
/**
*printing paths for rbtree
*/ 
void RBTree::paths(){
	printPaths(root);
}
/**
*finding max of 2 num
*/
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
/**
*height of node
*/
int height(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
/**
*printing in the given format
*/
void PrintNodeb(int indent, Node* node)
{
    while (--indent >= 0)
    cout << " ";
    cout << node->data <<"["<< height(node)-1<<"]"<< "\n";
}
/**
*printing bst
*/
void PrintNodeChildrenb(int indent, Node* node)
{
        if(node->left!=NULL){
		PrintNodeb(indent, node->left);
        PrintNodeChildrenb(indent + 1, node->left);}
        if(node->right!=NULL){
        PrintNodeb(indent, node->right);
        PrintNodeChildrenb(indent + 1, node->right);}
    
}
/**
*printing children rbtree
*/
void Printb(Node* roo)
{
   int indent = 0;
   PrintNodeb(indent, roo);
   PrintNodeChildrenb(indent + 1, roo);  
}
void PrintNodea(int indent, Node* node)
{
    while (--indent >= 0)
    cout << " ";
    cout << node->data <<"["<< height(node->left)-height(node->right)<<"]"<< "\n";
}
/**
*printing children of avl
*/
void PrintNodeChildrena(int indent, Node* node)
{
        if(node->left!=NULL){
		PrintNodea(indent, node->left);
        PrintNodeChildrena(indent + 1, node->left);}
        if(node->right!=NULL){
        PrintNodea(indent, node->right);
        PrintNodeChildrena(indent + 1, node->right);}
    
}
/**
*printing avl tree
*/
void Printa(Node* roo)
{
   int indent = 0;
   PrintNodea(indent, roo);
   PrintNodeChildrena(indent + 1, roo);  
}
/**
*printing redblack tree
*/
void PrintNoder(int indent, Node* node)
{  
    while (--indent >= 0)
    cout << " ";
    if(node->color==0)
    cout << node->data <<"["<< height(node->left)-height(node->right)<<"]"<<"["<<"RED"<<"]"<< "\n";
if(node->color==1)
    cout << node->data <<"["<< height(node->left)-height(node->right)<<"]"<<"["<<"BLACK"<<"]"<< "\n";
}

void PrintNodeChildrenr(int indent, Node* node)
{
        if(node->left!=NULL){
		PrintNoder(indent, node->left);
        PrintNodeChildrenr(indent + 1, node->left);}
        if(node->right!=NULL){
        PrintNoder(indent, node->right);
        PrintNodeChildrenr(indent + 1, node->right);}
    
}
/**
*printing rbtree
*/
void Printr(Node* roo)
{
   int indent = 0;
   PrintNoder(indent, roo);
   PrintNodeChildrenr(indent + 1, roo);  
}
/**
*printing rbtreee n the given format
*/
void RBTree::Prints(){
	Printr(root);
}
Node* newNode(int key)  
{  
    Node* node = new Node(key);  
    node->left = NULL;  
    node->right = NULL;   
    return(node);  
}  
/**
*right rotate function
*/
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;    
    x->right = y;  
    y->left = T2;    
    return x;  
}  
  /**
*left rotate function
*/ 
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
    y->left = x;  
    x->right = T2;     
    return y;  
}  
/**
*balancing tree
*/
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
/**
*insert
*/
Node* insert(Node* node, int key)  
{  
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->data)  
        node->left = insert(node->left, key);  
    else if (key > node->data)  
        node->right = insert(node->right, key);  
    else   
        return node;   
  
    int balance = getBalance(node);  
    if (balance > 1 && key < node->left->data)  
        return rightRotate(node);   
    if (balance < -1 && key > node->right->data)  
        return leftRotate(node);  
    
    if (balance > 1 && key > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }   
    if (balance < -1 && key < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    return node;  
}  
/**
*main 
*/
int main() {
	int w,p,tempa,i,j;
	int a[100];
int c=0;
	RBTree tree; 
	while(1){
		
	printf("Press a number for respective operation\n1. To insert a node in the BST and in the red-black tree\n2. To create AVL tree from the inorder traversal of the BST\n3. To print the inorder traversal of the BST/AVL/red-black tree\n4. To display all the paths in the BST/AVL tree/red-black tree\n5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation \n6. Exit\n");
    scanf("%d",&w);
    if(w==1)
    {
    	cout<<"enter data:  ";
    	scanf("%d",&p);
    	insertbst(p);
    	tree.insert(p);
    	a[c]=p;
    	printf("\n");
    	c++;
	}
	if(w==2){
		ahead=NULL;
	for(int kp=0;kp<c;kp++){
		ahead = insert(ahead, a[kp]);
	}	
	printf("AVL tree is created\n");		
	}
	if(w==3){
		if(bhead==NULL)
		printf("BST,RBT  arenot created\n");
		else{
		printf("The inorder transversal of BST,RBT,AVL is\n");	
		}
		inorder(bhead);
		printf("\n");
	}
	if(w==4){
		if(bhead==NULL)
		printf("BST,RBT are not created\n");
		else{ cout<<"BST:\n";
		printPaths(bhead);
	if(ahead==NULL)
	printf("AVL tree is not created\n");	
	else{cout<<"AVL:\n"; printPaths(ahead);}
	cout<<"RBT:\n"; tree.paths();}
	}
	if(w==5){
	printf("BST is\n");	
	Printb(bhead);
	printf("AVL Tree is\n");		
	Printa(ahead);
	printf("RBT is\n");	
	tree.Prints();
	}
	
    if(w==6){
    printf("Program is ended");	
    break;}
    
    }
	
	return 0;
}
