Quicksort
#include<stdio.h>
int a[100];

void swap(int low,int j){
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
}
int partition(int low,int high){
    int pivot;
    int i,j;
    pivot=a[low];
    i=low;
    j=high;
    while (i<j){
        do{
            i++;
        }while (i<=high&&a[i]<=pivot);
        do{
            j--;
        }while (j>=low&&a[j]>pivot);
        if(i<j)
        swap(i,j);  
    }
    swap(low,j);
    return j;   
}
void quicksort(int low,int high){
    if(low<high){
        int j=partition(low,high);
        quicksort(low,j);
        quicksort(j+1,high);
    }
}
void main(){
   int num;
   printf("Enter length of array\n");
   scanf("%d",&num);
   printf("Enter elements \n");
   for (int i = 0; i < num; i++)
   {
    scanf("%d",&a[i]);
   }
   a[num]=-1;
   quicksort(0,num);
   printf("Sorted elements \n");
   for (int i = 0; i < num; i++)
   {
    printf("%d ",a[i]);
}
}
