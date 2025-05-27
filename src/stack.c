#include "stack.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack *createStack(int value)
{
    struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
    if (newStack == NULL)
        throwMallocError();
    newStack->value = value;
    newStack->next = NULL;
    return newStack;
}

int push(struct Stack **top, struct Stack *new)
{
    if (new == NULL)
        return 0;
    new->next = *top;
    *top = new;
    return 1;
}

struct Stack *pop(struct Stack **top)
{
    if (*top == NULL)
        return NULL;
    struct Stack *temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    return temp;
}

void printStack(struct Stack *top)
{
    struct Stack *current = top;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void freeStack(struct Stack *top)
{
    struct Stack *current = top;
    struct Stack *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}
