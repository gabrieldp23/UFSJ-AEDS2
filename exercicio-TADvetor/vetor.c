#include "vetor.h"
#include <stdio.h>
#include <math.h>

Vetor novoVetor (float coordX, float coordY) {
    Vetor temp = { coordX, coordY };
    return temp;
}

void imprimirVetor (Vetor v, char* text) {
    printf("\n%s", text);
    printf("\nX = %.2f", v.x);
    printf("\nY = %.2f\n", v.y);
}

Vetor soma (Vetor v1, Vetor v2) {
    Vetor temp = { (v1.x+v2.x), (v1.y+v2.y) };
    return temp;
}

Vetor subtracao (Vetor v1, Vetor v2) {
    Vetor temp = { (v1.x-v2.x), (v1.y-v2.y) };
    return temp;
}

float normalizacao (Vetor v) {
    return sqrt((v.x*v.x)+(v.y*v.y));
}
