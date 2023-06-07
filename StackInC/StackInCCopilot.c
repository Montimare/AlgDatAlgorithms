// include stdio 
// and initialize main
// create a function for push
// create a function for pop
// create a function for display
// initialize a stack
// create a menu
// and initialize main
// create a function for push
// create a function for pop
// create a function for display
// initialize a stack
// create a menu
#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int);
void pop();
void display();
int main()
{
    int ch, val;
    printf("\n 1. Push in stack");
    printf("\n 2. Pop from stack");
    printf("\n 3. Display stack");
    printf("\n 4. Exit");
    do
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter value to be pushed : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n Exit");
            break;
        default:
            printf("\n Invalid Choice");
        }
    } while (ch != 4);
    return 0;
}
void push(int val)
{
    if (top == MAX - 1)
    {
        printf("\n Stack is full");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Deleted element is %d", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Stack is \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}



