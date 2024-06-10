import numpy as np

class Gauss1:
    def __init__(self, n, matrix, arr):
        self.N = n
        self.Matrix = np.array(matrix, dtype=float)
        self.Arr = np.array(arr, dtype=float)
        self.X = np.zeros(self.N)

    def printMatrix(self):
        for i in range(self.N):
            for j in range(self.N):
                print(f"{self.Matrix[i][j]:10.4f}", end=" ")
            print()

    def printArray(self):
        for i in range(self.N):
            print(f"b[{i}] = {self.Arr[i]:10.4f}")

    def elimination(self):
        for k in range(self.N - 1):
            for i in range(k + 1, self.N):
                p = -self.Matrix[i][k] / self.Matrix[k][k]
                for j in range(k, self.N):
                    self.Matrix[i][j] += p * self.Matrix[k][j]
                self.Arr[i] += p * self.Arr[k]

    def backSubstitution(self):
        self.X[self.N - 1] = self.Arr[self.N - 1] / self.Matrix[self.N - 1][self.N - 1]
        print(f"x[{self.N - 1}] = {self.X[self.N - 1]}")

        for i in range(self.N - 2, -1, -1):
            s = 0
            for j in range(i + 1, self.N):
                s += self.Matrix[i][j] * self.X[j]
            self.X[i] = (self.Arr[i] - s) / self.Matrix[i][i]
            print(f"x[{i}] = {self.X[i]}")

        print("The solution to the system of equations is:")
        for k in range(self.N):
            print(f"x[{k}] = {self.X[k]}")

# main function equivalent
if __name__ == "__main__":
    n = 3
    a = [
        [1, 2, -1],
        [-2, 3, 1],
        [4, -1, -3]
    ]

    b = [-1, 0, -2]

    gauss1 = Gauss1(n, a, b)
    gauss1.printMatrix()
    gauss1.printArray()
    gauss1.elimination()
    print("After pivoting:")
    gauss1.printMatrix()
    gauss1.printArray()
    gauss1.backSubstitution()