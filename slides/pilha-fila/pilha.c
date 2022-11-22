#include <stdio.h>

//-------

typedef struct {
    int valor;
} Item;

typedef struct TipoCelula* Apontador;
typedef struct TipoCelula{
    Item item;
    Apontador anterior;
} Celula;

typedef struct {
    Apontador ultimo;
    int tamanho;
} Pilha;

//-------

void esvaziar (Pilha* p) {
    p->ultimo = (Apontador) malloc(sizeof(Celula));
    p->ultimo->anterior = NULL;
    p->tamanho = 0; 
}

int vazia (Pilha* p) {
    return (p->tamanho == 0);
}

void empilhar (Item i, Pilha* p) {
    Apontador novo = (Apontador) malloc(sizeof(Celula));
    novo->item = i;
    novo->anterior = p->ultimo;
    p->ultimo = novo;
    p->tamanho++;
}

void desempilhar (Pilha* p, Item* i) {
    if (vazia(&p)) {
        printf("\nPilha vazia\n");
        return;
    } 
    *i = p->ultimo->item;
    Apontador temp = p->ultimo;
    p->ultimo = p->ultimo->anterior;
    free(temp);
    p->tamanho--;
}

int tamanho (Pilha* p) {
    return p->tamanho;
}

void topo (Pilha* p, Item* i) {
    *i = p->ultimo->item;
}

//-------

Pilha reverte(Pilha* p) {
    if (p->tamanho <= 1) return *p;

    Pilha pReverso;
    esvaziar(&pReverso);
    do {
        Item ultimoItem;
        desempilhar(p, &ultimoItem);
        empilhar(ultimoItem, &pReverso);
    } while (p->tamanho > 1);

    return pReverso;
}

//-------

void main () {
    Pilha pilha;
    esvaziar(&pilha);

    Item item;
    item.valor = 49;
    empilhar(item, &pilha);
    item.valor = 37;
    empilhar(item, &pilha);
    item.valor = 55;
    empilhar(item, &pilha);
    printf("--%d--", ((pilha.ultimo)->item).valor);

    Pilha reverso = reverte(&pilha);
    printf("--%d--", ((pilha.ultimo)->item).valor);
    

    desempilhar(&pilha, &item);
    desempilhar(&pilha, &item);
    desempilhar(&pilha, &item);
    //printf("--%d--", ((pilha.ultimo)->item).valor);
}