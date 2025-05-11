#include<stdio.h>
int st[100];
int top=-1;
int size;
void push(int a)
{
if(top==(size-1))
printf("Stack overflow \n");
else
{
top=top+1;
st[top]=a;
}
}
int pop()
{
if(top==-1)
printf("Stack underflow \n");
else
{
int a=st[top];
top=top-1;
return a;
}
}
void display()
{
int j;
printf("STACK\n");
for(j=top;j>=0;j--)
printf("%d\n",st[j]);
}
void main()
{
int i,c;
printf("Enter size of stack \n");
scanf("%d",&size);
do
{ 
printf("Enter 1 to push\n");
printf("Enter 2 to pop\n");
printf("Enter 3 to display\n");
printf("Enter 4 to exit\n");
printf("ENTER CHOICE!!!\n");
scanf("%d",&i);
switch(i)
{
case 1: printf("Enter element to be pushed in stack \n");
        scanf("%d",&c);
        push(c);
        break;
case 2:printf("Element pop : %d \n",pop());
       break;
case 3:display();
       break;
case 4:printf("Exiting program !!!\n");
       break;
default:printf("Invalid Choice");
}
}while(i!=4);
}

