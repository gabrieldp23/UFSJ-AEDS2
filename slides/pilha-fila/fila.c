#include <stdio.h>

//-------

typedef struct {
    int valor;
} Item;

typedef struct TipoCelula* Apontador;
typedef struct TipoCelula{
    Item item;
    Apontador proximo;
} Celula;

typedef struct {
    Apontador primeiro, ultimo;
    int tamanho;
} Fila;

//-------

void esvaziar (Fila* f) {
    f->primeiro = (Apontador) malloc(sizeof(Celula));
    f->primeiro->proximo = NULL;
    f->ultimo = f->primeiro;
    f->tamanho = 0;
}

int vazia (Fila* f) {
    return (f->tamanho == 0);
}

void enfileirar (Item i, Fila* f) {
    Apontador novo = (Apontador) malloc(sizeof(Celula));
    novo->item = i;
    novo->proximo = NULL;
    f->ultimo->proximo = novo;

    f->ultimo = novo;
    if (vazia(f)) f->primeiro = novo;

    f->tamanho++;
}

void desenfileirar (Fila* f, Item *i) {
    if (vazia(f)) {
        printf("\nFILA VAZIA\n");
        return;
    }

    *i = f->primeiro->item;

    Apontador temp = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    free(temp);

    f->tamanho--;
}

//---------

void main () {
    Fila fila;
    esvaziar(&fila);
    
    Item item;
    item.valor = 23;
    enfileirar(item, &fila);
    item.valor = 57;
    enfileirar(item, &fila);
    item.valor = 99;
    enfileirar(item, &fila);
    printf("\n%d\n", fila.primeiro->proximo->proximo->item.valor);

    desenfileirar(&fila, &item);
    printf("\n%d\n", fila.primeiro->item.valor);
}