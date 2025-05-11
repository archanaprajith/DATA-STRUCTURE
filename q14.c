/*Implement BST and its operations*/
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

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In-order\n ");
    inorder(root);
    printf("\n");
    root = delete(root, 30); 
    printf("In-order\n ");
    inorder(root);
    printf("\n");
     printf("Pre-order ");
    preorder(root);
    printf("\n");
     printf("Post-order traversal ");
    postorder(root);
    printf("\n");
}