/*
 * C Program to Perform Matrix Multiplication using Recursion
 */
#include <stdio.h>
#include <stdlib.h>

void multiply(int, int, int [][10], int, int, int [][10], int [][10]);

int main()
{
    int a[10][10], b[10][10], c[10][10] = {0};
    int m1 = 10, n1 = 10, m2 = 10, n2 = 10, i, j, k;

        for (i = 0; i < m1; i++){
            for (j = 0; j < n1; j++) {
                a[i][j] = rand() %100;
                b[i][j] = rand() %100;
            }
        }
    multiply(m1, n1, a, m2, n2, b, c);
}

void multiply (int m1, int n1, int a[10][10], int m2, int n2, int b[10][10], int c[10][10])
{
    static int i = 0, j = 0, k = 0;

    if (i >= m1)
    {
        return;
    }
    else if (i < m1)
    {
        if (j < n2)
        {
            if (k < n1)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
                multiply(m1, n1, a, m2, n2, b, c);
            }
            k = 0;
            j++;
            multiply(m1, n1, a, m2, n2, b, c);
        }
        j = 0;
        i++;
        multiply(m1, n1, a, m2, n2, b, c);
    }
}
