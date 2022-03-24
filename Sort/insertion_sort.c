#include <stdio.h>

void insertion_sort(int array[], int n);
void print_array(int array[], int n);

int main() {
	
	int array[] = { 10, 90, 1, 4, 55, 23, 49 };

	insertion_sort(array, 7);
	print_array(array, 7);

	return 0;
}
void insertion_sort(int array[], int n) {
	int i, k;
	int key;

	for (i = 1; i < n; i++) {
		key = array[i];
		k = i - 1;

		while(k>=0 && array[k]>key){
			array[k+1] = array[k];
			k--;
		}
		array[k+1] = key;
	}
}
void print_array(int array[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
}