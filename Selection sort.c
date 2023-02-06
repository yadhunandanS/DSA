#include <stdio.h>
void printArray(int *arr,int n) 
{
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n-----------------------------------------------------\n");
}
void selectionSort(int *arr,int n) 
{
    int min_index,temp;
    for(int i=0;i<n-1;i++)  
    {
        min_index = i;
        for(int j = i+1;j<n;j++)    
            if(arr[j]<arr[min_index])
                min_index = j;
        if(min_index!=i)    
        {
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[10] = {9,7,5,3,1,2,4,6,8,10};
    printArray(arr,10);
    selectionSort(arr,10);
    printArray(arr,10);
    return 0;
}

// Time Complexity:
// Avg and Worst Case: n^2
// Space Complexity: O(1)
