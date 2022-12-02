#include <math.h>
#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x);
}

double simpson_one_third(double a, double b, int n) {
    double h = (b - a) / n;
    double sum_odd_terms = 0.0, sum_even_terms = 0.0;
    for (int i = 1; i < n; ++i) {
        if (i & 1)
            sum_odd_terms += f(a + i * h);
        else
            sum_even_terms += f(a + i * h);
    }
    return h / 3 * (f(a) + f(b) + 4 * sum_odd_terms + 2 * sum_even_terms);
}

int main() {
    const double a = 0.0, b = 1.0;
    int n = 6;
    printf("Answer = %lf\n", simpson_one_third(a, b, n));
    return 0;
}