#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    double A, B, C, P, S;
	
	while (1) {
		printf("Введите длинны трёх сторон треугольника (A, B, C): ");

		if (scanf("%lf %lf %lf", &A, &B, &C)!=3) {
			printf("Ошибка: нужно ввести три числа.\n");
			return 0;
		}

		if (A <= 0 || B <= 0 || C <= 0) {
			printf("Ошибка: длина стороны не может быть меньше или равна нулю.\n");
			continue;
		}

		else if (A >= B + C || B >= A + C || C >= A + B) {
			printf("Ошибка: треугольник с такими сторонами не существует.\n");
			continue;
		}
		else {
			P = (A + B + C) / 2;
			S = sqrt(P * (P - A) * (P - B) * (P - C));
			printf("Площадь треугольника: %.2lf \n", S);
		}
	}
	return 0;
}