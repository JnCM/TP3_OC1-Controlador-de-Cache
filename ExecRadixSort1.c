#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmosOrdenacao.h"

int main(){
  int *vetor, i=0;
  FILE *ArqRead;
  vetor = (int *)malloc(1001*sizeof(int));
  ArqRead = fopen("cenario1.txt", "r");
  while(!feof(ArqRead)){
    fscanf(ArqRead, "%d", &vetor[i]);
    i++;
  }
  fclose(ArqRead);
  radix_sort(vetor, 1000);
  return 0;
}
