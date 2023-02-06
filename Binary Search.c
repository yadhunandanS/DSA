#include <stdio.h>
int main()
{
    int count = 0;
    int arr[64];
    for(int i=0;i<64;i++)   
        arr[i] = i+1;
    int key = 65;
    int low = 0,high = 63;
    while(low<=high) 
    {
        count++;
        int mid = (low+high)/2;
        if(arr[mid] == key) 
        {
            printf("Found");
            return 0;
        }
        else if(key>arr[mid])   
            low = mid+1;
        else 
            high = mid-1;
    }
    printf("Not Found with count of: %d",count);
    return 0;
}

//Time Complexity O(logn)
