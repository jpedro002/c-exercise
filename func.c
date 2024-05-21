#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fruta *criarFruta(int codigo, char *nome, int quantidade, float preco)
{
  Fruta *nova = (Fruta *)malloc(sizeof(Fruta));
  nova->codigo = codigo;
  strcpy(nova->nome, nome);
  nova->quantidade = quantidade;
  nova->preco = preco;
  nova->proxima = NULL;
  return nova;
}

void cadastrarFruta(Fruta **lista)
{
  int codigo, quantidade;
  char nome[50];
  float preco;

  printf("Digite o codigo da fruta: ");
  scanf("%d", &codigo);
  if (buscarFruta(*lista, codigo))
  {
    printf("Codigo ja existe!\n");
    return;
  }

  printf("Digite o nome da fruta: ");
  scanf("%s", nome);
  printf("Digite a quantidade: ");
  scanf("%d", &quantidade);
  printf("Digite o preço: ");
  scanf("%f", &preco);

  Fruta *nova = criarFruta(codigo, nome, quantidade, preco);
  nova->proxima = *lista;
  *lista = nova;

  printf("Fruta cadastrada com sucesso!\n");
}

void listarFrutas(Fruta *lista)
{
  Fruta *atual = lista;
  while (atual != NULL)
  {
    printf("\nCodigo: %d\nNome: %s\nQuantidade: %d\nPreço: %.2f\n\n",
           atual->codigo, atual->nome, atual->quantidade, atual->preco);
    atual = atual->proxima;
  }
}

Fruta *buscarFruta(Fruta *lista, int codigo)
{
  Fruta *atual = lista;
  while (atual != NULL)
  {
    if (atual->codigo == codigo)
    {
      return atual;
    }
    atual = atual->proxima;
  }
  return NULL;
}

void alterarFruta(Fruta *lista, int codigo)
{
  Fruta *fruta = buscarFruta(lista, codigo);
  if (fruta)
  {
    char nome[50];
    int quantidade;
    float preco;

    printf("Digite o novo nome da fruta: ");
    scanf("%s", nome);
    printf("Digite a nova quantidade: ");
    scanf("%d", &quantidade);
    printf("Digite o novo preço: ");
    scanf("%f", &preco);

    strcpy(fruta->nome, nome);
    fruta->quantidade = quantidade;
    fruta->preco = preco;

    printf("Fruta alterada com sucesso!\n");
  }
  else
  {
    printf("Fruta nao encontrada.\n");
  }
}

void excluirFruta(Fruta **lista, int codigo)
{
  Fruta *atual = *lista;
  Fruta *anterior = NULL;

  while (atual != NULL && atual->codigo != codigo)
  {
    anterior = atual;
    atual = atual->proxima;
  }

  if (atual == NULL)
  {
    printf("Fruta nao encontrada.\n");
    return;
  }

  if (anterior == NULL)
  {
    *lista = atual->proxima;
  }
  else
  {
    anterior->proxima = atual->proxima;
  }

  free(atual);
  printf("Fruta excluida com sucesso!\n");
}

void venderFruta(Fruta *lista, int codigo, int quantidade)
{
  Fruta *fruta = buscarFruta(lista, codigo);
  if (fruta)
  {
    if (fruta->quantidade < quantidade)
    {
      printf("Quantidade insuficiente em estoque.\n");
    }
    else
    {
      fruta->quantidade -= quantidade;
      registrarVenda(fruta->codigo, fruta->nome, quantidade, fruta->preco);
      printf("Venda realizada com sucesso!\n");
    }
  }
  else
  {
    printf("Fruta nao encontrada.\n");
  }
}

void registrarVenda(int codigo, char *nome, int quantidade, float preco)
{
  FILE *file = fopen("vendas.txt", "a");
  if (file)
  {
    fprintf(file,
            "Codigo: %d, Nome: %s, Quantidade: %d, Preço: %.2f, Total: %.2f\n",
            codigo, nome, quantidade, preco, quantidade * preco);
    fclose(file);
  }
  else
  {
    printf("Erro ao registrar a venda.\n");
  }
}
