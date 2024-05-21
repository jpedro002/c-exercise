#ifndef FUNCS_H
#define FUNCS_H

typedef struct Fruta
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct Fruta *proxima;
} Fruta;

Fruta *criarFruta(int codigo, char *nome, int quantidade, float preco);
void cadastrarFruta(Fruta **lista);
void listarFrutas(Fruta *lista);
Fruta *buscarFruta(Fruta *lista, int codigo);
void alterarFruta(Fruta *lista, int codigo);
void excluirFruta(Fruta **lista, int codigo);
void venderFruta(Fruta *lista, int codigo, int quantidade);
void registrarVenda(int codigo, char *nome, int quantidade, float preco);

#endif
