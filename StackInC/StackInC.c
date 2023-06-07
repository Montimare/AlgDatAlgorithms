#include <stdio.h>
#ifndef __STACK_H__
#define __STACK_H__

struct Stack; //forward declaration

struct Stack* stack_init(); //Legt einen neuen Stack an
void stack_push(struct Stack* stack, int data); //Legt ein Element auf den Stack
int stack_pop(struct Stack* stack); //Entnimmt ein Element vom Stack
void stack_delete(struct Stack* stack); //Löscht den Stack

int main(){


}



#endif