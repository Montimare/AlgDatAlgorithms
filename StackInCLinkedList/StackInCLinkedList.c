#include <stdio.h>
#include <stdlib.h>
#ifndef __STACK_H__
#define __STACK_H__

struct Stack; // forward declaration

void stack_push(struct Stack *stack, int key); // Legt ein Element auf den Stack
int stack_pop(struct Stack *stack);            // Entnimmt ein Element vom Stack
void stack_delete(struct Stack *stack);        // Löscht den Stack
void stack_print(struct Stack *stack);         // Print Stack
void stack_print_tail();                       // Print alles außer head

int main()
{
    stack_print(stack);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);
    stack_push(stack, 6);
    stack_print(stack);
    printf("popped number is %d.\n", stack_pop(stack));
    stack_delete(stack);
}

struct Stack
{
    int key;
    struct Stack *next;
};

void stack_push(struct Stack *stack, int key)
{
    if (stack->top >= MAX)
    {
        stack->top = -1;
    }
    if (stack->data[stack->top + 1] != 0)
    {
        printf("Stack voll, Element wird nicht eingefügt\n");
        return;
    }
    stack->data[stack->top + 1] = key;
    stack->top++;
    printf("Element wurde eingefügt.\n");
    return;
}

int stack_pop(struct Stack *stack)
{
    if (stack->top <= -1)
    {
        stack->top = 4;
    }
    int tmp = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
    return tmp;
}

void stack_delete(struct Stack *stack)
{
    while (stack != NULL)
    {
        struct Stack *head = stack;
        while (head->next != NULL)
        {
            head = head -> next;
        }
        free(head);
    }
}

void stack_print(struct Stack *stack) //so bad make recursive (but im too lazy)
{
    printf("Stack ist: ");
    printf("%d, ", stack->key);
    while (stack->next != NULL)
    {
        printf("%d, ", stack->key);
        stack = stack->next;
    }
    printf("\n");
    return;
}

void stack_print_tail(struct Stack *stack)
{
    printf("Stack ist: ");
    while (stack->next != NULL)
    {
        printf("%d, ", stack->key);
    }
    printf("\n");
    return;
}

#endif