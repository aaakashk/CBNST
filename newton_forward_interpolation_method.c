#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

void printForwardTable(double x[], double y[][MAX_SIZE], int N);
void generateForwardTable(double y[][MAX_SIZE], int N);
int fact(int n);

int main() {
    int N;
    double x[MAX_SIZE], y[MAX_SIZE][MAX_SIZE], p, xp, sum;
    memset(y, 0, sizeof(y));
    printf("Enter the number of values: ");
    scanf("%d", &N);
    printf("Enter value of x and y row-wise: \n");
    for (int i = 0; i < N; ++i) {
        scanf("%lf%lf", &x[i], &y[i][0]);
    }
    printf("Enter xp: ");
    scanf("%lf", &xp);
    p = (xp - x[0]) / (x[1] - x[0]);
    sum = y[0][0];

    generateForwardTable(y, N);
    printForwardTable(x, y, N);
    // calculate answer
    double resultant_p = 1;
    for (int i = 1; i < N; ++i) {
        resultant_p = resultant_p * (p - i + 1);
        sum += (resultant_p) / fact(i) * y[0][i];
    }
    printf("\nf(%.0lf) = %lf\n", xp, sum);
    return 0;
}

void generateForwardTable(double y[][MAX_SIZE], int N) {
    for (int j = 1; j < N; ++j) {
        for (int i = 1; i < N - j + 1; ++i) {
            y[i - 1][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
}

int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

void printForwardTable(double x[], double y[][MAX_SIZE], int N) {
    printf("FORWARD DIFFERENCE TABLE:\n");
    printf("|%4sx0%4s", "", "");

    for (int i = 0; i < N; ++i) {
        printf("|%4sy%d%4s", "", i, "");
    }
    printf("|\n");
    for (int i = 0; i < N; ++i) {
        printf("|%10.4lf", x[i]);
        for (int j = 0; j < N - i; ++j) {
            printf("|%10.4lf", y[i][j]);
        }
        printf("|");
        for (int j = N - i; j < N; ++j) {
            printf("%10s|", "");
        }
        printf("\n");
    }
}