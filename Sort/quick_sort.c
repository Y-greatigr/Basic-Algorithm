#include <stdio.h>

void quick_sort(int array[], int low, int high);
int partition(int array[], int low, int high);
void print_array(int array[], int n);
void swap(int* a, int* b);

int main() {

	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	quick_sort(array, 0, 6);
	print_array(array, 7);

	return 0;
}
void quick_sort(int array[], int low, int high) {

	int pivot;
	
	if (low < high) {
		pivot = partition(array, low, high);

		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}
int partition(int array[], int low, int high) {
	
	int i = low - 1, j;
	int pivot = array[high];

	for (j = low; j < high; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[j], &array[i]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return i + 1;
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