int soma_vetor(int v[], int tam) {
    if (tam == 0) return 0;   // caso base
    return v[tam - 1] + soma_vetor(v, tam - 1);
}