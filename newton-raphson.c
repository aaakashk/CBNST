#include <math.h>
#include <stdio.h>

double func(double x) {
    return x - exp(-x);
}

double derivative(double x) {
    return 1 + exp(-x);
}

int main() {
    int MAX_ITER, DECIMAL_PLACES;
    double x0, h, ALLOWED_ERROR;
    printf("Enter the value of x0 : ");
    scanf("%lf", &x0);
    printf("Enter decimal places and maximum iterations : ");
    scanf("%lf%d", &DECIMAL_PLACES, &MAX_ITER);

    for (int i = 0; i < MAX_ITER; ++i) {
        h = func(x0) / derivative(x0);
        printf("Iteration %2.2d, x = %lf\n", i, x0);
        if (fabs(h) < ALLOWED_ERROR) {
            printf("After %2.2d iterations, root = %.*lf\n", i + 1, DECIMAL_PLACES, x0);
            return 0;
        }
        x0 -= h;
    }

    printf("The required solution does not converge or iterations are insufficient.\n");
    return 1;
}