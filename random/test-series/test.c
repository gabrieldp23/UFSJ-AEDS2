#include <stdio.h>
#include <math.h>

double formula(double value) {
    return (value + 1 / sqrt(value));
}

void main() {
    const N_MAX_VALUE = 1000000;

    double sum = 0;
    for (double n = 1; n < N_MAX_VALUE; n += 2) {
        sum += formula(n);
        sum -= formula(n + 1);
    }

    printf("\n%lf\n", sum);
}
