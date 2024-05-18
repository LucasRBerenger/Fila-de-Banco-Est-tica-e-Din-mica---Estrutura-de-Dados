#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO
{
    char *nome;
    struct NO *prox;
} NO;

typedef struct FILA
{
    NO *ini;
    NO *fim;
} FILA;

void qinit(FILA *f)
{
    f->ini = NULL;
    f->fim = NULL;
}

void enqueue(FILA *f, char *n)
{
    NO *novo = (NO *)malloc(sizeof(NO));

    novo->nome = strdup(n);
    novo->prox = NULL;

    if (f->ini == NULL)
    {
        f->ini = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        // printf("%p\n", &novo);
        f->fim = novo;
    }
}

char *dequeue(FILA *f)
{
    NO *ptr = f->ini;

    if (f->ini == NULL)
    {
        printf("\nSem clientes para atendimento.\nRetornando ao menu...\n");
        ;
        return NULL;
    }
    else
    {
        f->ini = f->ini->prox;
        ptr->prox = NULL;
        char *nome = ptr->nome;
        free(ptr);
        return nome;
    }
}

int qisEmpty(FILA *f)
{
    return f->ini == NULL;
}

void imprimir(FILA *f)
{
    NO *ptr = f->ini;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("\n%s", ptr->nome);
            ptr = ptr->prox;
        }
    }
    else
    {
        printf("Fila vazia.\n");
        return;
    }
}
