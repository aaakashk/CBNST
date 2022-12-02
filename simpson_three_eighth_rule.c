#include <math.h>
#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x);
}

double simpson_three_eighth(double a, double b, int n) {
    double h = (b - a) / n;
    double sum_of_multiples_of_three = 0.0, sum_of_others = 0.0;
    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0)
            sum_of_multiples_of_three += f(a + i * h);
        else
            sum_of_others += f(a + i * h);
    }
    return 3 * h / 8 * (f(a) + f(b) + 2 * sum_of_multiples_of_three + 3 * sum_of_others);
}

int main() {
    const double a = 0.0, b = 1.0;
    const int n = 6;
    printf("Answer = %lf\n", simpson_three_eighth(a, b, n));
    return 0;
}