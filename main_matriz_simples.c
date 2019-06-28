#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,k;
    int A[10][10], B[10][10], C[10][10];
    for(i = 0; i < 10; i ++){
      for(j = 0; j < 10; j ++){
        A[i][j] = rand()%1000;
        B[i][j] = rand()%1000;
        C[i][j] = 0;
      }
    }
    //Multiplicar matrizes
    for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
        for(k = 0; k < 10; k++){
          C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
        }
      }
    }
    return 0;
  }
