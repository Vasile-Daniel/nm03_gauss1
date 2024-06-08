#include <iostream>
#include <cstdlib>
#include <vector>

/*
EXAMPLE: 
 | 1  2 -1 | -1 | x0 = 1;
 |-2  3  1 |  0 | x1 = 0;
 | 4 -1 -3 | -2 | x2 = 2;
Dupa pivotare:
 | 1  2 -1   | -1   |   2/7 = 0.2857
 | 0  7 -1   | -2   |   4/7 = 0.5714
 | 0  0 -2/7 | -4/7 |

 */
class Gauss1 {
private:
    int N;
    std::vector<std::vector<float>> Matrix;
    std::vector<float> Arr;
    std::vector<float> X;

public:
    Gauss1(int n, std::vector<std::vector<float>> matrix, std::vector<float> arr) : N(n), Matrix(matrix), Arr(arr) {
        X.resize(N); // Allocate space for the vector X
    }

    void printMatrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%10.4lf ", Matrix[i][j]);
            }
            printf("\n");
        }
    }

    void printArray() {
        for (int i = 0; i < N; i++) {
            printf("b[%d] = %10.4lf \n", i, Arr[i]);
        }
    }

    void pivot() {
        int k, i, j;
        double p;
        for (k = 0; k < N - 1; k++) {
            for (i = k + 1; i < N; i++) {
                p = -Matrix[i][k] / Matrix[k][k];
                for (j = k; j < N; j++) {
                    Matrix[i][j] = Matrix[i][j] + p * Matrix[k][j];
                }
                Arr[i] = Arr[i] + p * Arr[k];
            }
        }
    }

    void backSubstitution() {
        X[N - 1] = Arr[N - 1] / Matrix[N - 1][N - 1];
        std::cout << "x[" << N - 1 << "]=" << X[N - 1] << std::endl;

        for (int i = N - 2; i >= 0; i--) {
            double s = 0;
            for (int j = i + 1; j < N; j++) {
                s += Matrix[i][j] * X[j];
            }
            X[i] = (Arr[i] - s) / Matrix[i][i];
            printf("x[%d] = %lf \n", i, X[i]);
        }

        printf("The solution to the system of equations is:\n");
        for (int k = 0; k < N; k++) {
            printf("x[%d] = %lf \n", k, X[k]);
        }
    }
};

// main function
int main() {
    int n = 3;
    std::vector<std::vector<float>> a = {
        {1, 2, -1},
        {-2, 3, 1},
        {4, -1, -3}
    };

    std::vector<float> b = {-1, 0, -2};

    Gauss1 gauss1(n, a, b);
    gauss1.printMatrix();
    gauss1.printArray();
    gauss1.pivot();
    printf("After pivoting:\n");
    gauss1.printMatrix();
    gauss1.printArray();
    gauss1.backSubstitution();

    return 0;
}
