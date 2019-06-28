#ifndef AlgoritmosOrdenacao_H_INCLUDED
#define AlgoritmosOrdenacao_H_INCLUDED

void bubble_sort(int *Vetor, int TAM);
void Particao(int Esq, int Dir, int *i, int *j, int *vetor);
void Ordena(int Esq, int Dir, int *vetor);
void quick_sort(int *vetor, int n);
void radix_sort(int *vetor, int tamanho);
void troca(int *a, int *b);
void heapify(int *vetor, int n, int i);
void heap_sort(int *vetor, int n);

#endif
