#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* next;
}
*first = NULL;
int size = 0;
void display() 
{
    if(first == NULL)
        printf("Linked List is Empty\n");
    else 
    {
        struct node *temp = first;
        while(temp!=NULL) 
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void insert(int value,int index) 
{
    if(index<0 || index>size)
        printf("Cannot Insert in Index\n");
    else 
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        if(first == NULL || index == 0) 
        {
            //inserting the first element in Linked List
            temp->next = first;
            //if LL is empty, first is null else first has st. addr
            first = temp;
        }
        else   //inserting element in any index > 0
        { 
            struct node *prev = first;
            while(--index>0)
            prev=prev->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        size++;
    }
}
void search(int key) 
{
    if(first == NULL) 
        printf("Element Not Found");
    else 
    {
        struct node *temp = first;
        int position = 1;
        while(temp!=NULL) 
        {
            if(temp->data == key) 
            {
                printf("Element Found in %d position\n",position);
                return;
            }
            position++;
            temp = temp->next;
        }
        printf("Element Not Found\n");
    }
}
void delete(int key)
{
    //linked list is empty
    if(first == NULL) 
    {
        printf("Element Not Found\n");
        return;
    }
    if(first->data == key) //linked list has one element or delete starting element
    {
        struct node *temp = first;
        first = first->next;
        free(temp);
        printf("Element %d deleted\n",key);
        size--;
        return;
    }
    else   //delete element in middle or delete element in end
    {
        struct node *cur = first->next;
        struct node *prev = first;
        while(cur!=NULL) 
        {
            if(cur->data == key) 
            {
                prev->next = cur->next;
                free(cur);
                printf("Element %d deleted\n",key);
                size--;
                return;
            }       
            cur = cur->next;
            prev = prev->next;
        }
    }
    printf("Element Not Found\n");
}
void find_loop() 
{
    struct node *slow,*fast;
    slow = fast = first;
    while(fast->next!=NULL && fast->next->next!=NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) 
        {
            printf("Loop Detected\n");
            return;
        }
    }
    printf("Loop Not Detected\n");
}
void reverse() 
{
    if(first == NULL) printf("Linked List is Empty\n");
    else if(first->next == NULL) printf("Linked List has one element\n");
    else 
    {
        struct node *prev,*ahead;
        prev = NULL;
        ahead = first->next;
        while(ahead!=NULL) 
        {   
            first->next = prev;
            prev = first;
            first = ahead;
            ahead = ahead->next;
        }
        first->next = prev;
    }
}
void create_loop() 
{
    if(first!=NULL)
    {
        struct node *temp = first;
        while(temp->next!=NULL)
        temp = temp->next;
        temp->next = first;
    }
}
void check_Palindrome() 
{
//find middle of linked list.
//Use slow and fast pointer method.
//if fast->next is NULL, odd length
//if fast->next->next is NULL, even length
//reverse second half of linked list (Second half begins with slow)
//compare first half and second half (If equal, it's palindrome. Else not palindrome)
}
int main()
{
    int choice,value,index;
    while(1) 
    {
        printf("\nType 1 to insert into linked list\n");
        printf("Type 2 to display linked list\n");
        printf("Type 3 to delete element from linked list\n");
        printf("Type 4 to search element in linked list\n");
        printf("Type 5 to reverse the linked list\n");printf("Type 6 to find a loop within linked list\n");
        printf("Type 7 to create a loop within linked list\n");
        printf("Type 8 to check if linked list is Palindrome\n");
        printf("Type Anything Else to Exit!\n");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1: printf("Enter the value and index\n");
                    scanf("%d%d",&value,&index);
                    insert(value,index);
                    break;
            case 2: display();
                    break;
            case 3: printf("Enter the value to delete\n");
                    scanf("%d",&value);
                    delete(value);
                    break;
            case 4: printf("Enter the element to search within the list\n");
                    scanf("%d",&value);
                    search(value);
                    break;
            case 5: reverse();
                    break;
            case 6: find_loop();
                    break;
            case 7: create_loop();
                    break;
            case 8: //reverse second half and compare whether first and second halves are equal
            default: exit(0);
        }
    }
    return 0;
}