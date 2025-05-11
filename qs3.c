/*. Construct a BST to do following operations 
(a) Insert a set of values 
(b) Delete node containing maximum value.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    
}*root;

struct node* create(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node *root,int val){
    if(root==NULL){
        root=create(val);
    }
    else{
        if(root->data<val)
        root->right=insert(root->right,val);
        else
        root->left=insert(root->left,val);
    }
    return root;
}

struct node* findmin(struct node* root){
    while (root&&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node* delete(struct node *root , int val){
    if(root==NULL){
        return root;
    }
        if(root->data<val){
            root->right=delete(root->right,val);
        }else if(root->data>val){
            root->left=delete(root->left,val);
        }
        else{
            //one or no child
            if(root->left==NULL){
                struct node*temp =root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                struct node*temp =root->left;
                free(root);
                return temp;
            }
                //two child
                struct node*temp =findmin(root->right);
                root->data=temp->data;
                root->right=delete(root->right,temp->data);   
    }
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
    }
}

struct node* findmax(struct node* root){
    while (root&&root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

void main(){
    struct node *root =NULL;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In-order traversal before deletion: ");
    inorder(root);
     printf("\n");
    struct node *temp =NULL;
    temp=findmax(root);
    root=delete(root,temp->data);
    printf("In-order traversal after deletion: ");
    inorder(root);
}