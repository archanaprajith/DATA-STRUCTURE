
#include <stdio.h>
#include <stdlib.h>
struct node{
	int coef,exp;
	struct node *link;
}*head,*ptr;
struct node *getNode(int coef,int exp){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->coef=coef;
	temp->exp=exp;
	temp->link=NULL;
	return temp;
}
struct node *addTerms(struct node *head,int coef,int exp){
	struct node *temp=head;
	struct node *prev=NULL;
	while(temp!=NULL && temp->exp>exp){
		prev=temp;
		temp=temp->link;
	}
	if(temp!=NULL && temp->exp==exp){
		temp->coef+=coef;
	}
	else{
		struct node *new=getNode(coef,exp);
		if(prev==NULL){
			new->link=head;
			head=new;
		
		}else{
			new->link=prev->link;
			prev->link=new;
		}
	}
	return head;
}
struct node *multiply(struct node *p,struct node *q){
	struct node *r=NULL;
struct node*ptr1;
struct node*ptr2;
	for(ptr1=p;ptr1!=NULL;ptr1=ptr1->link){
		for(ptr2=q;ptr2!=NULL;ptr2=ptr2->link){
			int coef=ptr1->coef*ptr2->coef;
			int exp=ptr1->exp+ptr2->exp;
			r=addTerms(r,coef,exp);
		}
	}
	return r;
}
struct node *read(struct node *head){
	int c,e,m;
	printf("\nEnter number of terms:");
	scanf("%d",&m);
	printf("Enter the terms:");
	for(int i=0;i<m;i++){
		scanf("%d %d",&c,&e);
	struct node *temp=getNode(c,e);
	if(head==NULL){
		head=temp;
		ptr=head;
		}
	else{
		
		ptr->link=temp;
		ptr=temp;
	}
	}
	return head;
}
void print(struct node *r){
	ptr=r;
		while(ptr!=NULL){
			printf("%dx^%d",ptr->coef,ptr->exp);
			if(ptr->link!=NULL)
				printf("+");
			ptr=ptr->link;
		}
	}
void main(){
	struct node *p = NULL, *q = NULL, *r;
	printf("Enter 1st polynomial...");
	p=read(p);
	printf("Enter 2nd polynomial:");
	q=read(q);
	r=multiply(p,q);
	printf("Resultant polynomial:");
	print(r);
	}
