#include <stdio.h>

void selection_sort(int array[], int n);
void print_array(int array[], int n);
void swap(int* a, int* b);

int main() {

	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	selection_sort(array, 7);
	print_array(array, 7);

	return 0;
}
void selection_sort(int array[], int n) {
	int i, j;
	int min_index;

	for (i = 0; i < n-1; i++) {
		
		min_index = i;

		for (j = i+1; j < n; j++) {
			if (array[j] < array[min_index])
				min_index = j;
		}
		swap(&array[i], &array[min_index]);
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