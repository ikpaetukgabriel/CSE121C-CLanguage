//#include <stdio.h>
//#include <stdlib.h>
//#include "stack.h"
//
//// Utility function to initialize the stack
//struct stack* newStack(int capacity)
//{
//    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
//
//    pt->maxsize = capacity;
//    pt->top = -1;
//    pt->persons = allocate_space_for_new_person();
//
//    return pt;
//}
//
//// Utility function to return the size of the stack
//int size(struct stack *pt) {
//    return pt->top + 1;
//}
//
//// Utility function to check if the stack is empty or not
//int isEmpty(struct stack *pt) {
//    return pt->top == -1;                   // or return size(pt) == 0;
//}
//
//// Utility function to check if the stack is full or not
//int isFull(struct stack *pt) {
//    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
//}
//
//// Utility function to add an element `ptr_person` to the stack
//void push(struct stack *pt, struct person ptr_person)
//{
//    // check if the stack is already full. Then inserting an element would
//    // lead to stack overflow
//    if (isFull(pt))
//    {
//        printf("Overflow\nProgram Terminated\n");
//        exit(EXIT_FAILURE);
//    }
//
//    printf("Inserting %s, %s\n", ptr_person.last_name, ptr_person.last_name);
//
//    // add an element and increment the top's index
//    pt->persons[++pt->top] = ptr_person;
//}
//
//// Utility function to return the top element of the stack
//struct person* peek(struct stack *pt)
//{
//    // check for an empty stack
//    if (!isEmpty(pt)) {
//        return &pt->persons[pt->top];
//    }
//    else {
//        exit(EXIT_FAILURE);
//    }
//}
//
//// Utility function to pop a top element from the stack
//struct person* pop(struct stack *pt)
//{
//    // check for stack underflow
//    if (isEmpty(pt))
//    {
//        printf("Underflow\nProgram Terminated\n");
//        exit(EXIT_FAILURE);
//    }
//
//    printf("Removing %s, %s\n", peek(pt)->last_name, peek(pt)->first_name);
//
//    // decrement stack size by 1 and (optionally) return the popped element
//    return &pt->persons[pt->top--];
//}