#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "stack.h"

#define N 3

void printTowers(struct Stack *tower1, struct Stack *tower2, struct Stack *tower3, int id1, int id2, int id3)
{
    int fixedID;
    for (fixedID = 1; fixedID <= 3; fixedID++)
    {
        struct Stack *current = NULL;

        if (id1 == fixedID)
            current = tower1;
        else if (id2 == fixedID)
            current = tower2;
        else if (id3 == fixedID)
            current = tower3;

        printf("Torre %d: ", fixedID);
        printStack(current);
    }
}

int hanoi(int n, struct Stack **source, struct Stack **dest, struct Stack **aux, int idSource, int idDest, int idAux)
{
    if (n <= 0)
        return 0;

    int moves = 0;
    struct Stack *disk;
    if (n == 1)
    {
        disk = pop(source);
        if (disk == NULL)
            return 0;
        push(dest, disk);
        printf("Mover disco %d de Torre %d para Torre %d\n", disk->value, idSource, idDest);
        printTowers(*source, *dest, *aux, idSource, idDest, idAux);
        printf("\n");
        return 1;
    }

    moves += hanoi(n - 1, source, aux, dest, idSource, idAux, idDest);
    disk = pop(source);
    if (disk == NULL)
        return moves;
    push(dest, disk);
    printf("Mover disco %d de Torre %d para Torre %d\n", disk->value, idSource, idDest);
    printTowers(*source, *dest, *aux, idSource, idDest, idAux);
    printf("\n");
    moves += 1;
    moves += hanoi(n - 1, aux, dest, source, idAux, idDest, idSource);

    return moves;
}

int main(int argc, char const *argv[])
{
    int n;
    char input[BUFF_LINE_SIZE];

    if (argc > 1)
        n = strtol(argv[1], NULL, 10);
    else
    {
        printf("Insira a altura das torres (n): ");
        if (fgets(input, sizeof(input), stdin) != NULL)
            n = strtol(input, NULL, 10);
        else
            throwInputError();
    }

    struct Stack *tower1 = NULL;
    struct Stack *tower2 = NULL;
    struct Stack *tower3 = NULL;

    int i;
    for (i = n; i > 0; i--)
    {
        struct Stack *newDisk = createStack(i);
        if (!push(&tower1, newDisk))
            throwMallocError();
    }
    printf("Torres iniciais:\n");
    printTowers(tower1, tower2, tower3, 1, 2, 3);
    printf("\n");

    i = hanoi(n, &tower1, &tower2, &tower3, 1, 2, 3);
    printf("\n");

    printf("Torres finais:\n");
    printTowers(tower1, tower2, tower3, 1, 2, 3);
    printf("\n");

    printf("Total de movimentos: %d\n", i);

    freeStack(tower1);
    freeStack(tower2);
    freeStack(tower3);

    return 0;
}
