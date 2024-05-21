#include <stdio.h>
#include "func.h"

int main()
{
    Fruta *listaFrutas = NULL;
    int opcao, codigo, quantidade;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar fruta\n");
        printf("2. Listar frutas\n");
        printf("3. Buscar fruta\n");
        printf("4. Alterar fruta\n");
        printf("5. Excluir fruta\n");
        printf("6. Vender fruta\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarFruta(&listaFrutas);
            break;
        case 2:
            listarFrutas(listaFrutas);
            break;
        case 3:
            printf("Digite o codigo da fruta: ");
            scanf("%d", &codigo);
            Fruta *fruta = buscarFruta(listaFrutas, codigo);
            if (fruta)
            {
                printf("Codigo: %d\nNome: %s\nQuantidade: %d\nPreco: %.2f\n",
                       fruta->codigo, fruta->nome, fruta->quantidade, fruta->preco);
            }
            else
            {
                printf("Fruta nao encontrada.\n");
            }
            break;
        case 4:
            printf("Digite o codigo da fruta: ");
            scanf("%d", &codigo);
            alterarFruta(listaFrutas, codigo);
            break;
        case 5:
            printf("Digite o codigo da fruta: ");
            scanf("%d", &codigo);
            excluirFruta(&listaFrutas, codigo);
            break;
        case 6:
            printf("Digite o codigo da fruta: ");
            scanf("%d", &codigo);
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidade);
            venderFruta(listaFrutas, codigo, quantidade);
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
