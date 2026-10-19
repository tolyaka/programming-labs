#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 1000

int main() {
    setlocale(LC_ALL, "Russian");

    int a[N];

    srand((unsigned)time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = rand() % 30 - 15; //от -15 до 14
    }

    int last_index = -1;
    int prev_last_index = -1;

    for (int i = N - 1; i >= 0 && prev_last_index == -1; i--) {
        if (a[i] < 0) {
            if (last_index == -1) {
                last_index = i;
            }
            else {
                prev_last_index = i;
                //break; //убрать
            }
        }
    }

    if (last_index == -1 || prev_last_index == -1) {
        printf("В массиве недостаточно отрицательных элементов для расчета.\n");
        return 0;
    }

    printf("Предпоследний отрицательный: a[%d] = %d\n", prev_last_index, a[prev_last_index]);
    printf("Последний отрицательный:     a[%d] = %d\n\n", last_index, a[last_index]);

    printf("Участок массива (от a[%d] до a[%d]):\n", prev_last_index, last_index);
    for (int k = prev_last_index; k <= last_index; k++) {
        printf("  a[%d] = %d\n", k, a[k]);
    }
    printf("\n");

    //цикл фор
    int sum_for = 0;
    for (int i = prev_last_index; i <= last_index; i++) {
        sum_for += a[i];
    }
    printf(">>> Способ 1: цикл for\n");
    printf("  - Сумма элементов: %d\n", sum_for);

    //цикл ваил
    int sum_while = 0;
    int i = prev_last_index;
    while (i <= last_index) {
        sum_while += a[i];
        i++;
    }
    printf(">>> Способ 2: цикл while\n");
    printf("  - Сумма элементов: %d\n", sum_while);

    //цикл ду ваил
    int sum_do_while = 0;
    i = prev_last_index;
    do {
        sum_do_while += a[i];
        i++;
    } while (i <= last_index);
    printf(">>> Способ 3: цикл do-while\n");
    printf("  - Сумма элементов: %d\n", sum_do_while);

    return 0;
}