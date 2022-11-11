#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(float M[][MAX_SIZE], int N);

int main() {
    int i, j, k, n;
    float M[MAX_SIZE][MAX_SIZE], c, x[MAX_SIZE], sum = 0.0;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            scanf("%f", &M[i][j]);
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = j + 1; i <= n; i++) {
            c = M[i][j] / M[j][j];
            for (k = 1; k <= n + 1; k++) {
                M[i][k] = M[i][k] - c * M[j][k];
            }
        }
    }
    printf("The upper triangular matrix: \n");
    printMatrix(M, n);

    x[n] = M[n][n + 1] / M[n][n];
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + M[i][j] * x[j];
        }
        x[i] = (M[i][n + 1] - sum) / M[i][i];
    }
    printf("\nThe solution is: \n");
    for (i = 1; i <= n; i++) {
        printf("%c = %.2f\n", i + 119, x[i]);
    }
    return (0);
}

void printMatrix(float M[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N + 1; ++j) {
            printf("%-7.2lf ", M[i][j]);
        }
        printf("\n");
    }
}