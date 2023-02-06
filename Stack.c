#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int value)
{
    if(top == SIZE-1)  //If Stack is Full
{ 
    printf("Stack Overflow\n");
    return;}
    stack[++top] = value; //otherwise
}
void pop() 
{
    if(top==-1)
    printf("Stack Underflow\n");
    else
    top--;
}
int size() 
{
    return top+1;
}
int isEmpty()   //return 1 if empty. 0 if not empty.
{
    if(top == -1)
        return 1;
    return 0;
}
int isFull() 
{
    if(top == SIZE-1)
        return 1;
    return 0;
}
void display() 
{
    if(top == -1)
    printf("Stack is Empty\n");
    else 
    {
        for(int i = top;i>=0;i--)
        printf("%d\t",stack[i]);
    }
    printf("\n");
}


int main()
{
    for (int i = 10; i <= 50; i+=10)
        push(i);
        display();
    return 0;
}