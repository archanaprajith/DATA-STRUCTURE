/*4. Write a program to sort two arrays separately using quick sort
 and merge the two arrays and sort the merged array using merge sort.*/
#include <stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
    int partition(int A[],int low,int high){
    int pivot=A[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(A[j]<pivot){
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[high]);
    return (i+1);
}
void QuickSort(int A[],int low,int high){
    if(low<high){
        int pi=partition(A,low,high);
        QuickSort(A,low,pi-1);
        QuickSort(A,pi+1,high);
    }
}
void merge(int A[],int mid,int left,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=A[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[],int left,int right){
    if(left<right){
        int mid=left+((right-left)/2);
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        merge(A,mid,left,right);
    }
}
void Print(int A[],int x){
    for(int i=0;i<x;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}
int main(){
    int n1,n2;
    printf("enter the number of elements for 1st array:\n");
    scanf("%d",&n1);
    int A1[n1];
    printf("enter the %d elements for 1st array:\n",n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&A1[i]);
    }
    printf("enter the number of elements for 2nd array:\n");
    scanf("%d",&n2);
    int A2[n2];
    printf("enter the %d elements for 2nd array:\n",n2);
    for(int i=0;i<n2;i++){
        scanf("%d",&A2[i]);
    }
    QuickSort(A1,0,n1-1);
    printf("quick sort of 1st array:\n");
    Print(A1,n1);
    
    QuickSort(A2,0,n2-1);
    printf("Quick sort of 2nd array:\n");
    Print(A2,n2);
    
    int m=n1+n2;
    int MA[m];
    for(int i=0;i<n1;i++){
        MA[i]=A1[i];
    }
    for(int i=0;i<n2;i++){
        MA[n1+i]=A2[i];
    }
    MergeSort(MA,0,m-1);
    printf("After merging of the quick sort:\n");
    Print(MA,m);
    
    return 0;
}