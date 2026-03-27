#include <stdio.h>

void selectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
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

	selectionSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
