#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    const double epsilon = 0.001;
    double sum = 0.0, sign = 1.0;
    int n = 0;

    // способ 1 while
    printf(">>> Способ 1: while\n");
    while (fabs(4.0 * sum - M_PI) >= epsilon) {
        sum += sign / (2 * n + 1);
        sign = -sign;
        n++;
    }
    printf("  * Минимальное количество слагаемых: %d\n", n);

    // способ 2 do while
    printf(">>> Способ 2: do-while\n");
    sum = 0.0, sign = 1.0, n = 0;
    do {
        sum += sign / (2 * n + 1);
        sign = -sign;
        n++;
    } while (fabs(4.0 * sum - M_PI) >= epsilon);
    printf("  * Минимальное количество слагаемых: %d\n", n);

    // способ 3 for
    printf(">>> Способ 3: for\n");
    sum = 0.0, sign = 1.0;
    for (n = 0; fabs(4.0 * sum - M_PI) >= epsilon; n++) {
        sum += sign / (2 * n + 1);
        sign = -sign;
    }
    printf("  * Минимальное количество слагаемых: %d\n", n);

    return 0;
}