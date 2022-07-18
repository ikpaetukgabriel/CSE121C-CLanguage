//
// Created by Gabriel Ikpaetuk on 7/18/22.
//

#ifndef TASK06_STACK_H
#define TASK06_STACK_H
// Data structure to represent a stack
struct stack {
    int maxsize;    // define max capacity of the stack
    int top;
    struct person *persons;
};

struct stack *newStack(int capacity);

int size(struct stack *pt);

int isEmpty(struct stack *pt);

int isFull(struct stack *pt);

void push(struct stack *pt, struct person ptr_person);

struct person *peek(struct stack *pt);

struct person *pop(struct stack *pt);

#endif //TASK06_STACK_H
