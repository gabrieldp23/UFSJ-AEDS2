Pilha *reverte(Pilha p) {
    Pilha pReverso;
    esvaziar(pReverso);
    do {
        Item ultimoItem;
        desempilhar(p, p->ultimo, &ultimoItem);
        empilhar(&pReverso, ultimoItem);
    } while (p->ultimo != NULL);

    return pReverso;
}