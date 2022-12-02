// Use the trapezoidal rule with n = 6 to approximate integration from 0 to pi, sin2(x) dx.
// a = 0, b = pi, n = 6
#include <math.h>
#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x);
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double ans = (f(a) + f(b)) / 2;
    for (int i = 1; i < n; ++i) {
        ans += f(a + i * h);
    }
    return h * ans;
}

int main() {
    const double a = 0.0, b = 1.0;
    const int n = 6;
    printf("Answer = %lf\n", trapezoidal(a, b, n));
    return 0;
}