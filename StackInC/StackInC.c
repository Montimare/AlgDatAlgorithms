#include <stdio.h>
#include <stdlib.h>
#ifndef __STACK_H__
#define __STACK_H__
#define MAX 5

struct Stack; // forward declaration

struct Stack *stack_init();                    // Legt einen neuen Stack an
void stack_push(struct Stack *stack, int key); // Legt ein Element auf den Stack
int stack_pop(struct Stack *stack);            // Entnimmt ein Element vom Stack
void stack_delete(struct Stack *stack);        // Löscht den Stack
void stack_print(struct Stack *stack);         // Print Stack

int main()
{
    struct Stack *stack = stack_init();
    stack_print(stack);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_print(stack);
    printf("popped number is %d.\n", stack_pop(stack));
    stack_delete(stack);
}

struct Stack
{
    int data[MAX];
    int top;
};

struct Stack *stack_init()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = 0;

    return stack;
}

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
    stack->data[stack->top] = 0; //nicht unbedint nötig, da push den wert hier einfach überschreibt
    stack->top--;
    return tmp;
}

void stack_delete(struct Stack *stack)
{
    free(stack);
}

void stack_print(struct Stack *stack){
    printf("Stack ist: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ",stack->data[i]);
    }
    printf("\n");
    return;
}

#endif