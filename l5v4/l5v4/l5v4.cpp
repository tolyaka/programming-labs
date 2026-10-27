#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//#define N 10
//сделать ручной ввод массива
int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 1000;
    int size;

    printf("Введите размер массива (максимум %d): ", N);
    scanf("%d", &size);

    while (size > N || size < 2) {
        printf("Ошибка: размер массива должен быть от 2 до %d.\n", N);
        printf("Попробуйте еще раз: ");
        scanf("%d", &size);
    }

    double a[N];
    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {
        a[i] = (rand() % 4901 + 100) / 100.0;
    }

    printf("Массив:\n");
    for (int i = 0; i < size; i++) {
        printf("  a[%d] = %.2f\n", i, a[i]);
    }
    printf("\n");

    double min = 9999;
    double max = 0;
    int min_index = -1;
    int max_index = -1;

    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            if (a[i] < min) {
                min = a[i];
                min_index = i;
            }
        }
        else {
            if (a[i] > max) {
                max = a[i];
                max_index = i;
            }
        }
    }

    printf("Минимум среди нечётных индексов: a[%d] = %.2f\n", min_index, min);
    printf("Максимум среди чётных индексов:  a[%d] = %.2f\n", max_index, max);

    return 0;
}