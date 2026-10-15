#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

	int i, N, k = 0;
    double ax, ay, bx, by, cx, cy;
    double ab, ac, bc;
	
	printf("Введите количество треугольников: \n");
	scanf("%d", &N);
	while (N <= 0) {
		printf("Количество треугольников должно быть положительным числом. Введите заново: \n");
		scanf("%d", &N);
	}

    for(i = 1; i <= N; i++)
    {
		printf("%d-й треугольник:\n", i);
		printf("Введите координаты точки A (ax, ay): ");
		scanf("%lf %lf", &ax, &ay);

		printf("Введите координаты точки B (bx, by): ");
		scanf("%lf %lf", &bx, &by);

		printf("Введите координаты точки C (cx, cy): ");
		scanf("%lf %lf", &cx, &cy);

		ab = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
		ac = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));
		bc = sqrt(pow(cx - bx, 2) + pow(cy - by, 2));

		if (ab > ac && ab > bc) {
			k++;
		}
    }

    printf("Количество треугольников, где сторона AB больше двух других: %d\n", k);
    return 0;
}