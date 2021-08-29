#include <stdio.h>

void bubble_sort(int array[], int n);
void print_array(int array[], int n);
void swap(int* a, int* b);

int main() {

	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	bubble_sort(array, 7);
	print_array(array, 7);

	return 0;
}
void bubble_sort(int array[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		}
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_array(int array[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
}