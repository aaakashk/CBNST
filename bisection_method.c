#include <math.h>
#include <stdio.h>

int N;
const int MAX_ITER = 20;

struct equation {
    int coeff;
    int power;
};

double func(struct equation *, double);
void printEquation(struct equation *);

int main() {
    printf("Enter the number of terms in equation : ");
    scanf("%d", &N);

    struct equation equation[N];

    printf("Enter each term as coefficient followed up by its power :\n");
    for (int i = 0; i < N; ++i) {
        printf("Term %2d : ", i);
        scanf("%d%d", &equation[i].coeff, &equation[i].power);
    }
    int DECIMAL_PLACES;
    double a, b, c, e, ALLOWED_ERROR;
    printf("Enter the starting assumption of a and b: ");
    scanf("%lf%lf", &a, &b);
    printf("Enter the decimal places : ");
    scanf("%d", &DECIMAL_PLACES);
    ALLOWED_ERROR = DECIMAL_PLACES / (pow(10, DECIMAL_PLACES) * DECIMAL_PLACES);
    printEquation(equation);

    for (int i = 0; i <= MAX_ITER; i++) {
        c = (a + b) / 2;
        printf("Iteratoin %2.2d, value of c = %lf\n", i, c);
        if (fabs(e - c) < ALLOWED_ERROR) {
            printf("After %2.2d iterations, root = %.*lf\n", i + 1, DECIMAL_PLACES, c);
            return 0;
        }
        if (func(equation, a) * func(equation, c) < 0)
            b = c;
        else if (func(equation, b) * func(equation, c) < 0)
            a = c;
        e = c;
    }

    printf("\nRoot = %.*lf", DECIMAL_PLACES, c);
    return 0;
}

double func(struct equation equation[], double x) {
    double resultant = 0;
    for (int i = 0; i < N; ++i) {
        resultant += equation[i].coeff * pow(x, equation[i].power);
    }
    return resultant;
}

void printEquation(struct equation equation[]) {
    printf("The equation is %dx^%d ", equation[0].coeff, equation[0].power);

    for (int i = 1; i < N; ++i) {
        if (equation[i].coeff >= 0)
            printf("+");
        if (equation[i].power == 0)
            printf("%d = ", equation[i].coeff);
        else
            printf("%dx^%d ", equation[i].coeff, equation[i].power);
    }
    printf("0\n");
}