#include <stdio.h>

void countingSort(int arr[], int size){
	int max = arr[0];
	for(int i = 0; i < size; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	int count[max + 1];
	int output[size];
	
	for(int i = 0; i < max; i++){
		count[i] = 0;
	}
	
	for(int i = 0; i < size; i++){
		count[arr[i]]++;
	}
	
	// checker
//	for(int i = 0; i < max; i++){
//		printf("%d ", count[i]);
//	}

	for(int i = 1; i <= max; i++){
		count[i] += count[i - 1];
	}
	
	for(int i = size - 1; i >= 0; i--){
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	
	for(int i = 0; i < size; i++){
		arr[i] = output[i];
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

	countingSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
