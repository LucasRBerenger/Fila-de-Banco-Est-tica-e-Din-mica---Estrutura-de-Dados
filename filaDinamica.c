#include <stdio.h>
#include <stdlib.h>
#include "FILADIN.H"

void cadastrarCliente(FILA *filaQualquer)
{
    char resposta, vetorNome[20];

    printf("\nNome do cliente: ");
    scanf(" %49[^\n]*c", vetorNome);
    enqueue(filaQualquer, vetorNome);

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

void liberarAtendimento(FILA *filaNormal, FILA *filaPrioridade)
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

    FILA filaNormal;
    FILA filaPrioridade;
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

        default:
            printf("Opção Inválida!");
            break;
        }

    } while (opcao != 5);

    printf("\nVocê saiu do algoritmo!\n\n");
    return 0;
}
