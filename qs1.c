/*Create an SLL and perform the following operations on the SLL 
     1. Delete the highest element from the list. 
     2. Swap the node with smallest value with the last node value in the list.
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*head,*ptr,*ptr1;

struct node* create(int val){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->link=NULL;   
}
void insert(int val){
  struct node* temp=create(val);
  if (head==NULL)
  {
    head=temp;
  }
  else{
    ptr=head;
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
  }
}
void display(){
    if(head==NULL){
        printf("LIST EMPTY\n");
    }
    else{
    ptr=head;
    printf("List : ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
    }
}
void deleteHigh(){
     if(head==NULL){
        printf("LIST EMPTY\n");
    }
    else{
    int max=head->data;
    ptr=head;
    while(ptr!=NULL)
    {
        if(max<ptr->data){
            max=ptr->data;
        }
        ptr=ptr->link;
    }
    //if max value is in 1st node
    if(head->data==max){
        ptr=head;
        head=head->link;
        free(ptr);
    }
    else{
        ptr1=head;
        ptr=head->link;
        while ((ptr->data==max)||(ptr!=NULL))
        {
          //delete other nodes if it has max value      
            if(ptr->data==max){
                ptr1->link=ptr->link;
                free(ptr);
                break;
            }
            //if last node has max value
            if(ptr->link==NULL&&ptr->data==max){
                ptr1->link=NULL;
                free(ptr);
            }
            ptr1=ptr;
            ptr=ptr->link;
        }
        
    }
    }

}
void swapmin(){
    int min=head->data;
      struct node* temp= create(min);
      ptr=head;
      ptr1=head;
      //Find min 
      while(ptr!=NULL){
        if(min>ptr->data){
            min=ptr->data;
            temp=ptr;
           
        }
        ptr1=ptr; 
        ptr=ptr->link;
    }
    
    //swap
    int tem=temp->data;
    temp->data=ptr1->data;
    ptr1->data=tem;
}
void main(){
    insert(5);
    insert(2);
    insert(8);
    insert(7);
    insert(6);
    display();
    deleteHigh();
    display();
    swapmin();
    display();
}