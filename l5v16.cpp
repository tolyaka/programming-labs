#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//заметки:
// 100 элементов
//числа от 4 до 16
//

int main() {
	setlocale(LC_ALL, "Russian");

	const int size = 100;
	double arr[size];
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		arr[i] = 4.0 + (rand() % 1201) / 100.0;
	}

	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++) {
		printf("%7.2f", arr[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");

	double filter[size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		int calculation = (int)(arr[i] * 10) % 10;
		if (calculation % 2 == 0) {
			filter[count] = arr[i];
			count++;
		}
	}
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (filter[j] < filter[j + 1]) {
				double temp = filter[j];
				filter[j] = filter[j + 1];
				filter[j + 1] = temp;
			}
		}
	}

	printf("Отфильтрованный массив (числа с четной первой цифрой после запятой, отсортированные по убыванию):\n");
	if (count == 0) {
		printf("Нет элементов, удовлетворяющих условию.\n");
	}
	else {
		for (int i = 0; i < count; i++) {
			printf("%7.2f", filter[i]);
			if ((i + 1) % 10 == 0) {
				printf("\n");
			}
		}
		if (count % 10 != 0) {
			printf("\n");
		}
	}
	return 0;
}
