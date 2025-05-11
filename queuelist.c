#include<stdlib.h>
#include<stdio.h>


struct node{
  int data;
  struct node*link;
};

struct node*front=NULL;
struct node*rear=NULL;


struct node*enque(int val){
   struct node*temp=(struct node*)malloc(sizeof(struct node));
   
   if(temp==NULL){
   printf("memory allocation failded");
   return temp;
   }
   
   temp->data=val;
   temp->link=NULL;
   
    if(rear==NULL){
      front=rear=temp;
    }
    
   else{
     rear->link=temp;
     rear=temp;
  }
  printf("enqueued element to queue is: %d\n",val);
}

struct node*deque(int val){
       if(front==NULL){
       printf("under flow queue");
       return front;
       }
       
    struct node*temp=front;
    front=front->link;
    printf("dequeued element from queue is: %d\n",temp->data);
    free(temp);
    
   if(front==NULL){
      rear=NULL;
   }
}    
       
   void dispaly(){
       if(front==NULL){
       printf("queue is empty");
       return;
   }
   struct node*temp=front;
   printf("the queue element:");
   while(temp!=NULL){
   printf("%d\t",temp->data);
   temp=temp->link;
   }
   printf("\n");
   
  }
int main(){
int ch,val;
do{
 printf("1.enqueue in queue\n");
 printf("2. deque in queue\n");
 printf("3. dispaly queue\n");
 printf("4. exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to queue: ");
                scanf("%d", &val);
                enque(val);
                break;
            case 2:
                deque(val);
                break;
            case 3:
                dispaly();
                break;
            case 4:
                printf("Exiting......: ");
                break;    
          }
         	 
    }while(ch!=4);
    
  return 0;
}  
       
         
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
       
