#include <stdio.h>

typedef struct {
	int chave;
	/* outros componentes */
} TipoItem;

typedef struct Celula_str* Apontador;
typedef struct Celula_str {
	TipoItem item;
	Apontador prox;
} Celula;

typedef Apontador Lista;

//--------------

void criaLista(Lista* lista) {
	*lista = (Celula*) malloc(sizeof(Celula));
	(*lista)->prox = NULL;
}

int vazia(Lista lista) {
	return (lista->prox == NULL);
}

void insere(TipoItem x, Lista l) {
	/*Navega ate o ultimo para inserir*/
	for (; l->prox != NULL; l = l->prox);
	l->prox = (Celula*) malloc(sizeof(Celula));
	l->prox->item = x;
	l->prox->prox = NULL;
}

void retira(Apontador p, Lista lista, TipoItem* item) {
	/* Obs.: o item a ser retirado eh eh
	o seguinte ao apontado por p */
	if (vazia(lista) || p == NULL || p->prox == NULL) {
		printf(" Erro: Lista vazia ou posicao nao existe\n");
	}
	Apontador temp;
	temp = p->prox;
	*item = temp->item;
	p->prox = temp->prox;
	free(temp);
}

void main() {
	Lista l;
	criaLista(&l);

	TipoItem teste;
	insere(teste, l);
	insere(teste, l);

	retira(l, l, &teste);

	printf("---%d---", vazia(l));
}