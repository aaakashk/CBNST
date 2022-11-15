#include <math.h>
#include <stdio.h>

double f(double x) {
    return cos(x) - x * exp(x);
}

double formula(double a, double b) {
    return ((a * f(b) - b * f(a)) / (f(b) - f(a)));
}

int main() {
    int MAX_ITER, DECIMAL_PLACES;
    double a, b, c, e = 0.0;
    printf("Enter value of a, b, decimal places and maximum iterations : ");
    scanf("%lf%lf%d%d", &a, &b, &DECIMAL_PLACES, &MAX_ITER);
    double ALLOWED_ERROR = DECIMAL_PLACES / (pow(10, DECIMAL_PLACES) * DECIMAL_PLACES);

    for (int i = 0; i < MAX_ITER; ++i) {
        c = formula(a, b);
        printf("Iteration %2.2d, c = %lf\n", i, c);
        if (fabs(e - c) < ALLOWED_ERROR) {
            printf("After %2d iterations, root = %.*lf\n", i + 1, DECIMAL_PLACES, c);
            return 0;
        }
        if (f(a) * f(c) < 0)
            b = c;
        else if (f(b) * f(c) < 0)
            a = c;
        e = c;
    }
    printf("The required solution does not converge or iterations are insufficient.\n");
    return 1;
}