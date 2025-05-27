#ifndef STACK_H
#define STACK_H

struct Stack
{
    int value;
    struct Stack *next;
};

struct Stack *createStack(int value);
int push(struct Stack **top, struct Stack *new);
struct Stack *pop(struct Stack **top);
void printStack(struct Stack *top);
void freeStack(struct Stack *top);

#endif
