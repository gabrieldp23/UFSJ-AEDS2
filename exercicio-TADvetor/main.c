#include "vetor.h"
#include <stdio.h>

int main () {

	Vetor a = novoVetor(3, 4); 
	Vetor b = novoVetor(15, 20); 
	
	imprimirVetor(a, "Coordenadas do vetor A:");
	imprimirVetor(b, "Coordenadas do vetor B:");

	imprimirVetor(soma(a,b), "Soma dos vetores A e B:");
	imprimirVetor(subtracao(a,b), "Subtracao dos vetores A e B:");

	printf("\nNorma do vetor = %.2f", normalizacao(a));	
	printf("\nNorma do vetor = %.2f\n\n", normalizacao(b));	
	
}
