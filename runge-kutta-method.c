#include <math.h>
#include <stdio.h>

double f(double x, double y) {
    return x + y * y;
}
/* x0 = starting value of x
 * y  = starting value of y
 * x  = value of x for which we want the answer
 * h  = default
 */
double runge_kutta(double x0, double y, double x, double h) {
    double k1, k2, k3, k4;
    while (x0 < x) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + k1 / 2);
        k3 = h * f(x0 + 0.5 * h, y + k2 / 2);
        k4 = h * f(x0 + h, y + k3);

        y += 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 += h;
    }
    return y;
}

int main() {
    double x0, y0, x, h;
    printf("Enter x0, y0, x, h: ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x, &h);
    printf("Answer = %lf\n", runge_kutta(x0, y0, x, h));
    return 0;
}