#include <stdio.h>

void merge_sort(int array[], int low, int high);
void merge(int array[], int low, int mid, int high);
void print_array(int array[], int n);
void swap(int* a, int* b);

int main() {

	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	merge_sort(array, 0, 6);
	print_array(array, 7);

	return 0;
}
void merge_sort(int array[], int low, int high) {

	int mid;

	if (low < high) {
		mid = (low + high) / 2;

		merge_sort(array, low, mid);
		merge_sort(array, mid + 1, high);

		merge(array, low, mid, high);
	} 
}
void merge(int array[], int low, int mid, int high) {

	int i = low, n = low;
	int k = mid + 1;
	int rearr[100] = { 0, };

	while (i <= mid && k <= high) {
		if (array[i] < array[k])
			rearr[n++] = array[i++];
		else
			rearr[n++] = array[k++];
	}

	if (i > mid) {
		while(k <= high)
			rearr[n++] = array[k++];
	}
	else {
		while (i <= mid)
			rearr[n++] = array[i++];
	}	

	for (int j = low; j <= high; j++)
		array[j] = rearr[j];
}
void print_array(int array[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
}