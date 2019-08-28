#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node{
  struct Node *next;
  double data;
};
/**
* createnode a new node
*/
void createnode(struct Node *node,int n){ int j=0;
  struct Node *i;
  for(i=node;j<n;i=i->next,j++){
   i->next=(struct Node *)malloc(sizeof(struct Node)); 
   printf("Enter node value\n");
   scanf("%lf",&i->data);
}
i=NULL;
}
/**
* evaluating Xor
*/
int Xor(struct Node *node,int n,int x,int y){
int i,Xor=0;
for(i=1;i<=x;i++){
    node=node->next;
}
for(i=x;i<=y;i++){
    Xor=Xor^(int)node->data;
    node=node->next;
} 
return Xor;
}
/**
* 
*/
void func(struct Node *node,int n,int a[n][n],int i,int k){ if(k>=n||i>=n) return;
if(a[i][k]!=-1) return;
if(i>=k) return;
a[i][k]=Xor(node,n,i,k);
func(node,n,a,i,k+1);
func(node,n,a,i+1,i+2);
}
int main(){
int n,i,j,k;
printf("Enter value of n\n");
scanf("%d",&n);
struct Node *head=(struct Node *)malloc(sizeof(struct Node));
createnode(head,n); 
int a[n][n];
for(i=0;i<n;i++){
 for(j=0;j<n;j++){
 a[i][j]=-1;    
}
} 
func(head,n,a,0,1);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]==0){
  for(k=i;k<j;k++){
   count++;
}
}
}
}
printf("count=%d\n",count);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]==0){
  for(k=i;k<j;k++){
   printf("(%d,%d,%d)\n",i+1,k+2,j+1);
}
}
}
}
}
