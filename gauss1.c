#include <stdio.h>
// Project: Gauss Method 1
// Author: Vasile Daniel DAN 
// Start: Today, 6 June 2024

// The order must be preserved: int rows, int cols, double matrix[rows][cols]
void printMatrix(int n, double matrix[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%10.4lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printArray(int n, double arr[n]){
    int i;
    for (i = 0; i <n; i++) {
        printf("b[%d] = %10.4lf \n", i, arr[i]);
    }
}

void pivot(int n, double a[n][n], double b[n]){
    int k, i, j;
    double p;
    for (k = 0; k < n-1; k++) {
        for (i = k + 1; i < n; i++) {
            p = -a[i][k] / a[k][k];
            // printf("p = %lf\n", p);
            for (j = k; j < n; j++) {
                a[i][j] = a[i][j] + p * a[k][j];
            }
            b[i] = b[i] + p * b[k];
            printf("pivot b[%d] = %lf\n", i, b[i]);
        }
    }
}

void backSubstitution(int n, double x[n], double a[n][n], double b[n]){
    x[n-1] = b[n-1] / a[n-1][n-1];

    for(int i = n-2; i >= 0; i--){
        double s = 0;
        for(int j = i+1; j < n; j++){
            s = s + a[i][j]*x[j];
        }
        x[i] = (b[i] - s) / a[i][i];
    }

    printf("The solution to the system of equations is:\n");
    for(int k = 0; k < n; k++){
        printf("x[%d] = %lf \n", k, x[k]);
    }
}

int main() {
    int n = 3;
    double x[3];

    double a[3][3] = {
        { 1, 2, -1},
        {-2, 3, 1},
        { 4, -1, -3}
    };

    printf("Initial matrix:\n");
    printMatrix(n, a);

    double b[3] = {-1, 0, -2};

    printf("Initial vector b:\n");
    printArray(n, b);

    pivot(n, a, b);

    printf("After pivoting:\n");
    printMatrix(n, a);

    printf("Vector b after pivoting:\n");
    printArray(n, b);

    backSubstitution(n, x, a, b);

    return 0;
}
