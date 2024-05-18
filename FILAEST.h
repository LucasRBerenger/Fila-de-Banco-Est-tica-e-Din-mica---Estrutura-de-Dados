#include <stdio.h>
#include <stdlib.h>

#define FILAMAX 5

typedef struct fila
{
    char *dados[FILAMAX];
    int fim;
} fila;

void qinit(fila *f)
{
    int i;
    for (i = 0; i < FILAMAX; i++)
    {
        f->dados[i] = 0;
    }
    f->fim = 0;
}

int qisFull(fila *f)
{
    return (f->fim == FILAMAX);
}

int qisEmpty(fila *f)
{
    return (f->fim == 0);
}

void enqueue(fila *f, char *dado)
{
    if (f->fim == FILAMAX)
    {
        printf("Fila cheia\n");
    }
    else
    {
        f->dados[f->fim] = dado;
        f->fim++;
    }
}

char *dequeue(fila *f)
{
    int i;
    char *backup;

    if (f->fim == 0)
    {
        printf("Fila vazia\n");
        return NULL;
    }
    else
    {
        backup = f->dados[0];
        for (i = 0; i < f->fim; i++)
        {
            f->dados[i] = f->dados[i + 1];
        }
        f->fim--;
        return backup;
    }
}

void imprimir(fila *f)
{
    int i;
    for (i = 0; i < f->fim; i++)
    {
        printf("\n%s", f->dados[i]);
    }
}
