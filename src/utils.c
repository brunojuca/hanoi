#include <stdio.h>
#include <stdlib.h>

int throwInputError()
{
    fprintf(stderr, "Error reading input\n");
    exit(1);
}

int throwMallocError()
{
    fprintf(stderr, "Error in memory allocation\n");
    exit(1);
}
