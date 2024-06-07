#include <iostream>
#include <cstdlib>
#include <vector>

class Gauss1{
private:
    int N;
    std::vector<std::vector<float>> Matrix;
    std::vector<float> Arr; 
    std::vector<float> X; 

public: 
    Gauss1(int n,  std::vector<std::vector<float>> matrix, std::vector<float> arr):N(n), Matrix(matrix), Arr(arr){}

    // Gauss1(int n,  std::vector<std::vector<float>> matrix, std::vector<float> arr){
    //     N = n; 
    //     Matrix = matrix; 
    //     Arr = arr; 
    // }

    void printMatrix() {
        int i, j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%10.4lf ", Matrix[i][j]);
                // std::cout << Matrix[i][j];
            }
            printf("\n");
            // std::cout << std::endl; 
        }
    }

    void printArray(){
        int i; 
        for (i = 0; i < N; i++) {
            printf("b[%d] = %10.4lf \n", i, Arr[i]);
        }
    }

    void pivotare(){
        int k,i,j; 
        double p; 
        for (k = 0; k < N-1; k++) {
            for (i = k + 1; i < N; i++) {
                p = -Matrix[i][k] / Matrix[k][k]; 
                // printf("p = %lf\n", p);
                for (j = k; j < N; j++) {
                    Matrix[i][j] = Matrix[i][j] + p * Matrix[k][j];
                }
                Arr[i] = Arr[i] + p * Arr[k]; 
                // printf("pivot b[%d] = %lf\n", i, Arr[i]);
            }
        }
    }

    void backSubstitution(){
        X[N-1] = Arr[N-1] / Matrix[N-1][N-1]; 

        for(int i = N-2; i >= 0; i--){
            double s = 0; 
            for(int j = i+1; j < N; j++){
                s = s + Matrix[i][j]*X[j];
            }
            X[i] = (Arr[i] - s) / Matrix[i][i];
        }

        printf("Solutia sistemului de ecuatii este:\n");
        for(int k = 0; k < N; k++){
            printf("x[%d] = %lf \n", k, X[k]);
        }
    }
};
int main(){
    int n = 3; 
    std::vector<std::vector<float>> a = {
        { 1, 2, -1},
        {-2, 3, 1},
        { 4, -1, -3}
    };

    std::vector<float> b = {-1, 0, -2};

    Gauss1 gauss1(n, a, b);
    gauss1.printMatrix();
    gauss1.printArray(); 
    gauss1.pivotare();
    printf("After pivoting:\n");
    gauss1.printMatrix();
    gauss1.printArray();    
    gauss1.backSubstitution();


    return 0; 
}