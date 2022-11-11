#include <math.h>
#include <stdio.h>

int main() {
    double coeff[3];  // a = coeff[0], b = coeff[1], c = coeff[2]
    printf("Enter the coefficients of x^2, x and constant: ");
    scanf("%lf%lf%lf", &coeff[0], &coeff[1], &coeff[2]);
    printf("The equation is %.2lfx^2 + (%.2lf)x + (%.2lf) = 0\n", coeff[0], coeff[1], coeff[2]);

    double discriminant = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2];

    if (discriminant > 0) {
        printf("Roots are real and distinct.\n");
        double root_1 = (-coeff[1] + sqrt(discriminant)) / (2 * coeff[0]);
        double root_2 = (-coeff[1] - sqrt(discriminant)) / (2 * coeff[0]);
        printf("Roots = %.2lf and %.2lf\n", root_1, root_2);
    } else if (discriminant == 0) {
        printf("Roots are real and equal.\n");
        double roots = -coeff[1] / (2 * coeff[0]);
        printf("Roots = %.2lf\n", roots);
    } else {
        printf("Roots are imaginary.\n");
        double real = -coeff[1] / (2 * coeff[0]);
        double imag = sqrt(-discriminant) / (2 * coeff[0]);
        printf("Roots = %.2lf + %.2lfi and %.2lf - %.2lfi\n", real, imag, real, imag);
    }
    return 0;
}