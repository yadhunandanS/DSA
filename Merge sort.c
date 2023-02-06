#include <stdio.h>
void printArray(int *arr,int n) 
{
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n-----------------------------------------------------\n");
}
void mergeSort(int *arr,int low,int high) 
{
    if(low<high)    
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        sortByMerging(arr,low,mid,high);
    }
}
int main()
{
    int arr[10] = {9,7,5,3,1,2,4,6,8,10};
    printArray(arr,10);
    mergeSort(arr,0,6);
    printArray(arr,10);
    return 0;
}
// sortby merging

#include <stdio.h>
#include<stdlib.h>
void printArray(int *arr,int n) 
{
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n-----------------------------------------------------\n");
}
void sortByMerging(int *arr,int low,int mid,int high)   
{
    int *n1,*n2,i,j,k;
    int size_n1,size_n2;
    size_n1 = mid-low+1;
    size_n2 = high-mid;
    n1 = (int*)malloc(sizeof(int)*size_n1);
    n2 = (int*)malloc(sizeof(int)*size_n2);
    for(i=0;i<size_n1;i++)
        n1[i] = arr[low+i];
    for(j=0;j<size_n2;j++)
        n2[j] = arr[mid+1+j];
    i = j = 0;
    k = low;
    while(i<size_n1 && j<size_n2)   
    {
        if(n1[i]<=n2[j])
            arr[k++] = n1[i++];
        else 
            arr[k++] = n2[j++];
    }
    while(i<size_n1)
        arr[k++] = n1[i++];
    while(j<size_n2)
        arr[k++] = n2[j++];
}   
void mergeSort(int *arr,int low,int high) 
{
    if(low<high)    
    {
        int mid = (low+high)/2;
        printf("Low = %d,high = %d,mid = %d\n",low,high,mid);
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        sortByMerging(arr,low,mid,high);
    }
}
int main()
{
    int arr[10] = {9,7,5,3,1,2,4,6,8,10};
    printArray(arr,10);
    mergeSort(arr,0,9);
    printArray(arr,10);
    return 0;
}

// Time Complexity: nlogn (Best/Avg/Worst)
// Space Complexity: n
// Stable: Yes
