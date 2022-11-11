#include <math.h>
#include <stdio.h>

double func(double x) {
    return x - exp(-x);
}

double derivative(double x) {
    return 1 + exp(-x);
}

int main() {
    int MAX_ITER;
    double x0, h, ALLOWED_ERROR;
    printf("Enter the value of x0 : ");
    scanf("%lf", &x0);
    printf("Enter allowed error and maximum iterations : ");
    scanf("%lf%d", &ALLOWED_ERROR, &MAX_ITER);

    for (int i = 0; i < MAX_ITER; ++i) {
        h = func(x0) / derivative(x0);
        printf("Iteration %2d, x = %lf\n", i, x0);
        if (fabs(h) < ALLOWED_ERROR) {
            printf("After %2d iterations, root = %.4lf\n", i + 1, x0);
            return 0;
        }
        x0 -= h;
    }

    printf("The required solution does not converge or iterations are insufficient.\n");
    return 1;
}