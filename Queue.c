#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int f = -1;
int r = -1;
void push(int value) 
{
    if(f == (r+1)%SIZE)
    //if queue is full
    printf("Queue Overflow\n");
    else if(f == -1) //if queue is empty
    {
        f = r = 0;
        queue[r] = value;
    }
    else //if queue is neither full nor empty
    {
        r = (r+1)%SIZE;
        queue[r] = value;
    }
}
void pop() 
{
    if(f == -1) //if queue is empty
        printf("Queue Underflow\n");
    else if(f == r) //if queue has only one element
        f = r = -1;
    else //if queue has >1 element
        f = (f+1)%SIZE;
}
void display() 
{
    if(f == -1) 
        printf("Queue is Empty\n");
    else 
    {
        for(int i=f;i!=r;i=(i+1)%SIZE)
            printf("%d\t",queue[i]);
            printf("%d\t",queue[r]);
    }
}
int front() 
{
    return queue[f];
}
int back()
{
    return queue[r];
}
int size() 
{
//WRITE YOUR EFFICIENT CODE TO FIND SIZE OF A CIRCULAR QUEUE
return -1;
}
int empty() 
{
    if(front == -1)
        return 1;
            return 0;
}
int main()
{
    for(int i = 10;i<=60;i+=10)
    push(i);
    pop();
    pop();
    push(60);
    push(70);
    display();
    return 0;
}