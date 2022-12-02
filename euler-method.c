#include <math.h>
#include <stdio.h>

double f(double x, double y) {
    return x + 2 * y;
}

double euler(double x0, double y, double x, double h) {
    while (x0 < x) {
        y += h * f(x0, y);
        x0 += h;
    }
    return y;
}

int main() {
    double x0, y0, x, h;
    printf("Enter x0, y0, x, h: ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x, &h);
    printf("Answer = %lf\n", euler(x0, y0, x, h));
    return 0;
}