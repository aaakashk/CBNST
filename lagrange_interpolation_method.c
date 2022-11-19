#include <stdio.h>

#define MAX_SIZE 10

double calculate(int x[], int y[], int N, int value);

int main() {
    int N, x0, x[MAX_SIZE], y[MAX_SIZE];
    printf("Enter the number of x and y values: ");
    scanf("%d", &N);
    printf("Enter the x and y values row-wise:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    printf("Enter x for which you want to find: ");
    scanf("%d", &x0);

    printf("\nANSWER = %lf\n", calculate(x, y, N, x0));
    return 0;
}

double calculate(int x[], int y[], int N, int value) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        double prod = y[i];
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                prod = prod * (value - x[j]) / (x[i] - x[j]);
            }
        }
        sum += prod;
    }
    return sum;
}