#include <stdio.h>

typedef int Chave;
typedef struct {
	Chave chave;
	/* outros componentes */
} Item;

typedef struct Celula_str* Apontador;
typedef struct Celula_str {
	Item item;
	Apontador prev, prox;
} Celula;

typedef struct { 
	Apontador primeiro, ultimo; 
} Lista;

//------------

void FLVazia(Lista* lista) {
	lista->primeiro = (Apontador) malloc(sizeof(Celula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->prox = NULL;
}

int vazia(Lista* lista) {
	return (lista->primeiro == lista->ultimo);
}

void inserir(Item x, Lista* lista) {
	Apontador p = (Apontador) malloc(sizeof(Celula));
	lista->ultimo->prox = p;
	p->prev = lista->ultimo;
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = x;
	lista->ultimo->prox = NULL;
}

void remover(Apontador p, Lista* lista, Item* item) {
	/* --- Obs.: o item a ser retirado eh
	o seguinte ao apontado por p --- */
	Apontador q;
	if (vazia(lista) || p == NULL || p->prox == NULL) {
		printf(" Erro: Lista vazia ou posicao nao existe\n");
		return;
	}
	q = p->prox;
	*item = q->item;
	p->prox = q->prox;
	if (q->prox != NULL) {
		q->prox->prev = q->prev;
	}
	if (p->prox == NULL) {
		lista->ultimo = p;
	}
	if (vazia(lista)) {
		lista->ultimo = lista->primeiro;
		lista->primeiro->prox = NULL;
	}
	free(q);
}

//----------------

void imprime(Lista lista) {
	Apontador Aux;
	Aux = lista.primeiro->prox;
	while (Aux != NULL) {
		printf("\n%d\n", Aux->item.chave);	// fixed
		Aux = Aux->prox;
	}
}

//------------------

void main() {
	Lista l;
	FLVazia(&l);
	printf("---%d---", vazia(&l));

	Item i;
	i.chave = 23;
	inserir(i, &l);
	i.chave = 29;
	inserir(i, &l);
	i.chave = 21;
	inserir(i, &l);

	remover(l.ultimo->prev, &l, &i);
	imprime(l);
}