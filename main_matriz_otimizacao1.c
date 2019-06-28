#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, k, l = 0, c = 0;
    int C[10][10], A1[5][5], A2[5][5], A3[5][5], A4[5][5];
    int B1[5][5], B2[5][5], B3[5][5], B4[5][5];
    //======== Preenche aleatoriamente matrizes A1 a B4 ========
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            A1[i][j] = rand() % 1000;
            A2[i][j] = rand() % 1000;
            A3[i][j] = rand() % 1000;
            A4[i][j] = rand() % 1000;
            B1[i][j] = rand() % 1000;
            B2[i][j] = rand() % 1000;
            B3[i][j] = rand() % 1000;
            B4[i][j] = rand() % 1000;
        }
    }
    //======== Inicializa a matriz resultante com zeros ========
    for(i = 0; i < 10; i++){
      for(j = 0; j < 10; j++){
        C[i][j] = 0;
      }
    }
    for(i = 0; i < 5; i++){//Responsavel pela mudança de linha.
      for(j = 0; j < 5; j++){//Responsavel pela mudança de coluna.
        for(k = 0; k < 5; k ++){//posição da linha e coluna que será multiplicada.
          C[l][c] = C[l][c] + (A1[i][k]* B1[k][j]) + (A2[i][k]* B3[k][j]); //primeiro quadrante.
          C[l][c+5] = C[l][c+5] + (A1[i][k] * B2[k][j]) + (A2[i][k] * B4[k][j]); //segundo quadrante.
          C[l+5][c] = C[l+5][c] + (A3[i][k]* B1[k][j]) + (A4[i][k] * B3[k][j]); //terceiro quadrante.
          C[l+5][c+5] = C[l+5][c+5] + (A3[i][k]* B2[k][j]) + (A4[i][k] * B4[k][j]); //quarto quadrante.
        }
        c++;//escolha da coluna da matriz resultante.
      }
      c = 0;//sempre que vamos mudar de linha devemos zerar a coluna para começarmos a colocar os valores na coluna zero.
      l++;//escolha da linha matriz resultante.
    }
    return 0;
}
