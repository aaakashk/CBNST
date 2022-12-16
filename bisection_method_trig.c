#include <math.h>
#include <stdio.h>

double func(double x) {
    return x - cos(x);
}

int main() {
    double a, b, c;
    printf("Enter the starting assumption of a and b : ");
    scanf("%lf%lf", &a, &b);
    for (int i = 1; i <= 20; ++i) {
        c = (a + b) / 2;
        printf("Iteration %2d, value of c = %lf\n", i, c);
        if (func(a) * func(c) < 0)
            b = c;
        else if (func(b) * func(c) < 0)
            a = c;
    }
    printf("Root = %.4lf", c);
}