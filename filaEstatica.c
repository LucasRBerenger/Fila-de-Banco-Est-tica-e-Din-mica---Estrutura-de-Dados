#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILAEST.h"

void cadastrarCliente(fila *filaQualquer)
{
    char resposta, vetorNome[20];
    if (!qisFull(filaQualquer))
    {
        printf("\nNome do cliente: ");
        scanf(" %19[^\n]*c", vetorNome);

        char *nomeCliente = malloc(strlen(vetorNome) + 1); // Aloca memória
        strcpy(nomeCliente, vetorNome);                    // Copia o nome para a memória alocada
        enqueue(filaQualquer, nomeCliente);                // Armazena o ponteiro na fila

        // Essa parte separada foi feita com ajuda, porque a fila normal estava sendo sobrescrita pela fila prioridade com essa função: enqueue(filaQualquer, vetorNome);

        printf("Deseja cadastrar outro cliente (S/N)? ");
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's')
        {
            cadastrarCliente(filaQualquer); // Chama recursivamente para cadastrar outro cliente
        }
        else
        {
            printf("\nRetornando para o menu...\n");
        }
    }
    else
    {
        printf("\nFila cheia. Cadastro Bloqueado.\n");
    }
}

void liberarAtendimento(fila *filaNormal, fila *filaPrioridade)
{
    char resposta;

    printf("\n****FILA NORMAL****");
    printf("\nAtendimento ao cliente %s.", dequeue(filaNormal));
    printf("\nAtendimento ao cliente %s.\n", dequeue(filaNormal));

    printf("\n****FILA PRIORIDADE****");
    printf("\nAtendimento ao cliente %s.\n", dequeue(filaPrioridade));

    printf("Deseja liberar outro cliente (S/N)? ");
    scanf(" %c", &resposta);

    if (resposta == 'S' || resposta == 's')
    {
        liberarAtendimento(filaNormal, filaPrioridade);
    }
    else
    {
        printf("\nRetornando para o menu...\n");
    }
}
int main()
{

    fila filaNormal;
    fila filaPrioridade;
    int opcao;

    qinit(&filaNormal);
    qinit(&filaPrioridade);

    do
    {
        printf("\n1 - Cadastrar atendimento comum\n2 - Cadastrar atendimento prioritário\n3 - Liberar atendimento\n4 - Imprimir\n5 - Sair\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarCliente(&filaNormal);
            break;

        case 2:
            cadastrarCliente(&filaPrioridade);
            break;

        case 3:
            liberarAtendimento(&filaNormal, &filaPrioridade);
            break;

        case 4:
            printf("\n****FILA NORMAL****");
            imprimir(&filaNormal);
            printf("\n****FILA PRIORIDADE****\n");
            imprimir(&filaPrioridade);
            break;
        }

    }

    while (opcao != 5);

    printf("\nEncerrando programa...\n\n");
    return 0;
}
