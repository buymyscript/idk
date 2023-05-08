//B1 Количество отрицательных значений функции имеющих не четную целую часть

#include <stdio.h>
#include <math.h>

#define A -5.0
#define B 5.0
#define H 0.1

double F(double x) {
    return x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x, 3) - pow(x, 2)));
}

void main() {
    double x, y;
    int count = 0;


    for (x = A; x <= B; x += H) {
        y = F(x);
        printf("%10.4f%10.4f\n", x, y);

        if ((y < 0) && ((int)fabs(y) % 2 != 0)) {
            count++;
        }
    }

    printf("Counter of numbers = %d\n", count);
}
