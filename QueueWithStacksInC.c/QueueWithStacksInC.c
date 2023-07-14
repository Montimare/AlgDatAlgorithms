#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int key;
    struct Stack *next;
};

int poppedNumber;
int dequeuedNumber;

struct Stack* createStack(){
    struct Stack *head = malloc(sizeof(struct Stack));
    head->key = 0;
    head->next = NULL;
    return head;
}

struct Stack* pop(struct Stack* head){
    poppedNumber = head -> key;
    head = head->next;
    return head;
}

struct Stack* push(struct Stack* head, int key){
    struct Stack *newHead = malloc(sizeof(struct Stack));
    newHead->key = key;
    newHead->next = head;
    head = newHead;
    return head;
}

struct Stack* enqueue(struct Stack* head1, struct Stack* head2, int key){
    if (head2 == NULL)
    {
        /* code */
    }
    
}

struct Stack* dequeue(){

}

int main(){
    struct Stack *stack1 = createStack();
    struct Stack *stack2 = createStack();
    while (1)
    {
        int input;
        printf("Wähle Option aus:\n0: \n1: \n2: \n3: ");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            /* code */
            break;
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        
        default:
            return 0;
        }
    }
    
}