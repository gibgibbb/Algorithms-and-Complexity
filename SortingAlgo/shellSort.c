#include <stdio.h>

void shellSort(int arr[], int size){
	for(int gap = size / 2; gap != 0; gap /= 2){
		for(int i = gap; i < size; i++){
			int temp = arr[i];
			int j;
			for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void displaySorted(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

int main(){

	int arr[5] = {29, 3, 10, 45, 11};
	int size = sizeof(arr)/sizeof(arr[0]);

	shellSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
