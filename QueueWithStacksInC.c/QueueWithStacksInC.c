#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int key;
    struct Stack *next;
};

int poppedNumber;
int dequeuedNumber;

struct Stack *createStack()
{
    struct Stack *head = malloc(sizeof(struct Stack));
    head->key = NULL;
    head->next = NULL;
    return head;
}

struct Stack *pop(struct Stack *head)
{
    poppedNumber = head->key;
    if (head->next != NULL)
    {
        struct Stack *newhead = head->next;
        free(head);
        return newhead;
    }
    else
    {
        head->key = NULL;
        return head;
    }
}

struct Stack *push(struct Stack *head, int key)
{
    if (head->key == NULL)
    {
        head->key = key;
        return head;
    }
    struct Stack *newHead = malloc(sizeof(struct Stack));
    newHead->key = key;
    newHead->next = head;
    head = newHead;
    return head;
}

void printStack(struct Stack *head)
{
    printf("Stack top to bottom:\n");
    struct Stack *headtmp = head;
    if (headtmp != NULL)
    {
        printf("%d, ", headtmp->key);
        while (headtmp->next != NULL)
        {
            headtmp = headtmp->next;
            printf("%d, ", headtmp->key);
        }
    }
    printf("\n");
    return;
}

void enqueue(struct Stack **head1, struct Stack **head2, int key)
{
    if ((*head2)->key == NULL)
    {
        *head1 = push(*head1, key);
    } else
    {
        while ((*head2)->key != NULL)
        {
            *head2 = pop(*head2);
            *head1 = push(*head1, poppedNumber);
        }
        *head1 = push(*head1, key);
    }

    while ((*head1)->key != NULL)
    {
        *head1 = pop(*head1);
        *head2 = push(*head2, poppedNumber);
    }
}

void dequeue(struct Stack **head2)
{
    pop(*head2);
    dequeuedNumber = poppedNumber;
}

int main()
{
    struct Stack *stack1 = createStack();
    struct Stack *stack2 = createStack();
    while (1)
    {
        int input;
        printf("Wähle eine Option aus:\n0: print\n1: enqueue\n2: dequeue");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            int input2;
            printf("Gib key: ");
            scanf("%d", &input2);
            enqueue(&stack1, &stack2, input2);
            // break;
        case 0:
            printStack(stack1);
            printStack(stack2);
            break;
        case 2:
            dequeue(&stack2);
            printf("popped: %d\n", poppedNumber);
            break;
        default:
            return 0;
        }
    }
}