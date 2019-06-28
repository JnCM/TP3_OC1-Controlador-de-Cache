#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmosOrdenacao.h"

int main(){
  int *vetor, i=0;
  FILE *ArqRead;
  vetor = (int *)malloc(10001*sizeof(int));
  ArqRead = fopen("cenario2.txt", "r");
  while(!feof(ArqRead)){
    fscanf(ArqRead, "%d", &vetor[i]);
    i++;
  }
  fclose(ArqRead);
  bubble_sort(vetor, 10000);
  return 0;
}
