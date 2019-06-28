#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,k;
    int B[10][10],A[10][10],C[10][10];
    for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
        A[i][j] = rand() % 1000;
        B[i][j] = rand() % 1000;
        C[i][j] = 0;
      }
    }
    for(k = 0; k < 10; k++){
      for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
          C[k][j] = C[k][j] + A[k][i] * B[i][j];
        }
      }
    }
    return 0;
}
