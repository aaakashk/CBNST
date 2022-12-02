#include <math.h>
#include <stdio.h>

double f(double x, double y) {
    return x * x + y;
}

double euler(double x, double y, double h) {
    return y + h * f(x, y);
}
// new_y1 = stores the new y1 value calculated in each approximation
double new_y1(double x, double y, double x1, double y1, double h) {
    double e = 0.00001, new_y1 = y1;
    do {
        y1 = new_y1;
        new_y1 = y + 0.5 * h * (f(x, y) + f(x1, y1));
    } while (fabs(new_y1 - y1) > e);
    return new_y1;
}
/* x0 = starting value of x
 * y  = starting value of y
 * x  = value of x for which we want the answer
 * h  = default
 */
double euler_modified(double x0, double y, double x, double h) {
    while (x0 < x) {
        double x1 = x0 + h;
        double old_y = euler(x0, y, h);  // old_y = stores the starting y value of each iteration
        double new_y = new_y1(x0, y, x1, old_y, h);
        x0 = x1;
        y = new_y;
    }
    return y;
}

int main() {
    double x0, y0, x, h;
    printf("Enter x0, y0, x, h: ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x, &h);
    printf("Answer = %lf\n", euler_modified(x0, y0, x, h));
    return 0;
}