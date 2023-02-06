#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int value) 
{
    if(top == SIZE-1)  //If Stack is Full
    {   
        printf("Stack Overflow\n");
        return;
    }
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
int isEmpty()  //return 1 if empty. 0 if not empty.
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
int peek() 
{
    return stack[top];
}
void evaluatePostfix(char *str) 
{
    for(int i=0;str[i]!='\0';i++) {
    if(str[i]>=48 && str[i]<=57) //if it's a number
    push(str[i]-48); //converting the ascii value to actual numeric value
    else  //if it's an operator
    {
        if(isEmpty()) 
        {
            printf("INVALID EXPRESSION"); return;
        }
        int op2 = peek();
        pop();
        if(isEmpty()) 
        {
            printf("INVALID EXPRESSION"); return;
        }
        int op1 = peek();
        pop();
        switch(str[i]) 
        {
            case '+': push(op1+op2); break;
            case '-': push(op1-op2); break;
            case '*': push(op1*op2); break;
            case '/': push(op1/op2); break;
            case '%': push(op1%op2); break;
            default: printf("INVALID EXPRESSION\n");
        }
    }
}
if(size() == 1)
    printf("%d",peek());
else
    printf("INVALID EXPRESSION");
}
int main()
{
    char str[25] = "62*82/-";
    evaluatePostfix(str);
    return 0;
}