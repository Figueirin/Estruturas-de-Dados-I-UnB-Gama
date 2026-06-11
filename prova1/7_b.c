int busca(char vet[], int tam, char alvo) {
    for (int i = 0; i < tam; i++)
        if (vet[i] == alvo) return i;
    return -1;
}