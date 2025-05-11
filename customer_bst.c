

#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *lchild,*rchild;
}*root,*ptr;
struct node *create(int val) {
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}
struct node *insert(struct node *root,int val) {
	if(root==NULL)
		return create(val);
	if(val<root->data)
		root->lchild=insert(root->lchild,val);
	else if(val>root->data)
		root->rchild=insert(root->rchild,val);
	return root;
}
struct node *minVal(struct node *root) {
	ptr=root;
	while(ptr!=NULL)
		ptr=ptr->lchild;
	return ptr;
}
struct node *deletemin(struct node *root) {
	if(root==NULL)
		return NULL;
	if(root->lchild==NULL) {
		struct node*temp=root->rchild;
		free(root);
		return temp;
	}
	root->lchild=deletemin(root->lchild);
	return root;
}

int height(struct node *root) {
	if (root==NULL) return -1;
	int left=height(root->lchild);
	int right=height(root->rchild);
	return (left>right?left:right)+1;
}

int count(struct node *root) {
	if (root==NULL) return 0;
	return 1+count(root->lchild)+count(root->rchild);
}

int level(struct node *root,int data,int lvl) {
	if (root==NULL) return -1;
	else if (root->data==data) return lvl;
	int leftlevel=level(root->lchild,data,lvl+1);
	if(leftlevel!=-1) return leftlevel; int rightlevel=level(root->rchild,data,lvl+1);
}
void preorder(struct node *root) {
	if(root!=NULL) {
		printf("%d ",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void main() {
	int n,data,l;
	root=NULL;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	printf("Enter the values:");
	for(int i=0; i<n; i++) {
		scanf("%d",&data);
		root=insert(root,data);
	}
	printf("Binary Search Tree is:");
	preorder(root);
	printf("\nHeight of BST:%d",height(root));
	printf("\nNumber of nodes of BST:%d",count(root));
	printf("\nEnter node to find level:");
	scanf("%d",&l);
	printf("\nLevel of node:%d",level(root,l,1));
	deletemin(root);
	printf("\nBinary Search Tree after deleting:");
	preorder(root);
}
