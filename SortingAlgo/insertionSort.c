#include <stdio.h>

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int key = arr[i];
		int j;
		for(j = i - 1; j >= 0 && arr[j] > key; j--){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
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

	insertionSort(arr, size);
	displaySorted(arr, size);
	
	return 0;
}
