#include <stdio.h>
char st[100];
int top=-1;
void push(char a)
{
top=top+1;
st[top]=a;
}
char pop()
{
char c=st[top];
top=top-1;
return c;
}
int precedence(char a)
{
switch(a)
{
case '+': return 1;
         break;
case '-': return 1;
         break;
case '*': return 2;
         break;
case '/': return 2;
         break;
case '^': return 3;
         break;
         }
return -1;
}
void main()
{
char exp[100],x;
int i;
printf("Enter expression \n");
scanf("%s",exp);
push('(');
for(i=0;exp[i]!='\0';i++)
{
if(((int)exp[i]>=48)&&((int)exp[i]<=57))
printf("%c",exp[i]);
else if(((int)exp[i]>=65)&&((int)exp[i]<=90))
 printf("%c",exp[i]);
else if(((int)exp[i]>=97)&&((int)exp[i]<=122))
 printf("%c",exp[i]);                 
 else if(exp[i]=='(')
 push(exp[i]);
 else if(exp[i]==')')
 {
 while((x=pop())!='(')
 printf("%c",x);
 }
 else
 {
 while(precedence(st[top])>=precedence(exp[i]))
 printf("%c",pop());
 push(exp[i]);
 }
 }
 while(top!=0)
 printf("%c",pop());
 } 
                           
                  
