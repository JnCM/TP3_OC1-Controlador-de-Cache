#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmosOrdenacao.h"

//Radix Sort -> https://pt.wikipedia.org/wiki/Radix_sort
//Quick e Bubble Sort -> Livro Ziviani
//Heap Sort -> https://www.geeksforgeeks.org/heap-sort/

void bubble_sort(int *Vetor, int TAM){
  int i, j;
  int Aux;
  for(i=0; i<TAM-1; i++){
    for(j=1; j<TAM-i; j++){
      if(Vetor[j] < Vetor[j-1]){
        Aux = Vetor[j];
        Vetor[j] = Vetor[j-1];
        Vetor[j-1] = Aux;
      }
    }
  }
}

void Particao(int Esq, int Dir, int *i, int *j, int *vetor){
  int pivo;
  int aux;
  *i = Esq;
  *j = Dir;
  pivo = vetor[(*i + *j)/2];
  do{
    while(pivo > vetor[*i]){
      (*i)++;
    }
    while(pivo < vetor[*j]){
      (*j)--;
    }
    if(*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*i)++;
      (*j)--;
    }
  }while(*i <= *j);
}

void Ordena(int Esq, int Dir, int *vetor){
  int i, j;
  Particao(Esq, Dir, &i, &j, vetor);
  if(Esq < j){
    Ordena(Esq, j, vetor);
  }
  if(i < Dir){
    Ordena(i, Dir, vetor);
  }
}

void quick_sort(int *vetor, int n){
  Ordena(0, n-1, vetor);
}

void radix_sort(int *vetor, int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;
    b = (int *)calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior){
    	    maior = vetor[i];
    	}
    }
    while (maior/exp > 0) {
      int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++){
    	    bucket[(vetor[i] / exp) % 10]++;
    	}
    	for (i = 1; i < 10; i++){
    	    bucket[i] += bucket[i - 1];
    	}
		for (i = tamanho - 1; i >= 0; i--){
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	}
		for (i = 0; i < tamanho; i++){
    	    vetor[i] = b[i];
    	}
		exp *= 10;
    }
    free(b);
}

void troca(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(int *vetor, int n, int i){
  int Maior = i;
  int Esq = 2*i + 1;
  int Dir = 2*i + 2;
  if((Esq < n) && (vetor[Esq] > vetor[Maior])){
    Maior = Esq;
	}
  if((Dir < n) && (vetor[Dir] > vetor[Maior])){
    Maior = Dir;
	}
  if(Maior != i){
    troca(&vetor[i], &vetor[Maior]);
    heapify(vetor, n, Maior);
  }
}

void heap_sort(int *vetor, int n){
  int i;
  for(i = n / 2 - 1; i >= 0; i--){
    heapify(vetor, n, i);
  }
  for(i=n-1; i>=0; i--){
    troca(&vetor[0], &vetor[i]);
    heapify(vetor, i, 0);
  }
}
