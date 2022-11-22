typedef struct {
    float x, y;
} Vetor;

Vetor novoVetor (float, float);
void imprimirVetor (Vetor, char*);
Vetor soma (Vetor, Vetor);
Vetor subtracao (Vetor, Vetor);
float normalizacao (Vetor);