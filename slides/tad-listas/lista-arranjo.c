#include <stdio.h> 

#define inicioArranjo 1
#define maxTam 1000

typedef int TipoChave;
typedef int Apontador;

typedef struct {
	TipoChave chave;
	/* outros componentes */
} TipoItem;

typedef struct {
	TipoItem item[maxTam];
	Apontador primeiro, ultimo;
} TipoLista;

void fLVazia(TipoLista* lista) {
	lista->primeiro = inicioArranjo;
	lista->ultimo = lista->primeiro;
}

int vazia(TipoLista* lista) {
	return (lista->primeiro == lista->ultimo);
}

void insere(TipoItem x, TipoLista* lista) {
	if (lista->ultimo > maxTam) {
		printf("Lista esta cheia\n");
	} else {
		lista->item[lista->ultimo - 1] = x;
		lista->ultimo++;
	}
}

void retira(Apontador p, TipoLista* lista, TipoItem* item) {
	int aux;
	if (vazia(lista) || p > lista->ultimo) {
		printf("Erro: posicao nao existe\n");
		return;
	}
	*item = lista->item[p - 1];
	lista->ultimo--;
	for (aux = p; aux < lista->ultimo; aux++) {
		lista->item[aux - 1] = lista->item[aux];
	}
}

void imprime(TipoLista* lista) {
	int aux;
	for (aux = lista->primeiro - 1; aux <= (lista->ultimo - 2); aux++) {
		printf("%d\n", lista->item[aux].chave);
	}
}


//-------------

void main() {
	TipoLista l;
	fLVazia(&l);

	TipoItem itenzinho;
	insere(itenzinho, &l);
	
	TipoItem lixo;
	retira(2, &l, &lixo);

	imprime(&l);
}