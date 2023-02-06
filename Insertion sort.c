#include <stdio.h>
void printArray(int *arr,int n) 
{
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n-----------------------------------------------------\n");
}
void insertionSort(int *arr,int n) 
{
    int temp;
    for(int i=1;i<=n-1;i++) 
    {
        for(int j=i;j>0 && arr[j]<arr[j-1];j--) 
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}
int main()
{
    int arr[10] = {9,7,5,3,1,2,4,6,8,10};
    printArray(arr,10);
    insertionSort(arr,10);
    printArray(arr,10);
    return 0;
}

// Time Complexity:
// Best Case: n
// Avg and Worst Case: n^2
// Space Complexity: O(1)
