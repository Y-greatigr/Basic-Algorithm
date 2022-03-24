#include <stdio.h>

void heap_sort(int array[], int n);
void heapify(int array[], int n, int i);
void print_array(int array[], int n);
void swap(int* a, int* b);

int main() {

	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	heap_sort(array, 7);
	print_array(array, 7);

	return 0;
}
void heap_sort(int array[], int n) {

	int i;

	for (i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i);
	
	for (i = n - 1; i >= 0; i--) {
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}
void heapify(int array[], int n, int i) {

	int largest = i;
	int a = 2 * i + 1;
	int b = 2 * i + 2;

	if (a<n && array[a]>array[largest])
		largest = a;

	if (b<n && array[b]>array[largest])
		largest = b;

	if (largest != i) {
		swap(&array[largest], &array[i]);
		heapify(array, n, largest);
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