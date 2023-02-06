#include <stdio.h>
void printArray(int *arr,int n) 
{
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n-----------------------------------------------------\n");
}
void bubbleSort(int *arr,int n) 
{
    int temp,j,swapped;
    for(int i=1;i<n;i++)  
    { 
        swapped = 0;
        for(j=0;j<=n-i-1;j++)   
        {
            if(arr[j]>arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
        return;
    }
}
int main()
{
    int arr[10] = {9,7,5,3,1,2,4,6,8,10};
    printArray(arr,10);
    bubbleSort(arr,10);
    printArray(arr,10);
    return 0;
}

  // Time Complexity: 
  // Best: n
  // Avg & Worst: n^2
  // Space Complexity: 
  // O(1)
