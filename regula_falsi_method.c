#include <math.h>
#include <stdio.h>

double f(double x) {
    return cos(x) - x * exp(x);
}

double formula(double a, double b) {
    return ((a * f(b) - b * f(a)) / (f(b) - f(a)));
}

int main() {
    int MAX_ITER;
    double a, b, c, e = 0.0, ALLOWED_ERROR;
    printf("Enter value of a, b, ALLOWED_ERROR and maximum iterations : ");
    scanf("%lf%lf%lf%d", &a, &b, &ALLOWED_ERROR, &MAX_ITER);

    for (int i = 0; i < MAX_ITER; ++i) {
        c = formula(a, b);
        printf("Iteration %2d, c = %lf\n", i, c);
        if (fabs(e - c) < ALLOWED_ERROR) {
            printf("After %2d iterations, root = %.4lf\n", i + 1, c);
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