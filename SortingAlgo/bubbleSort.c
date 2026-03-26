#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void displaySorted(int arr[], int n);

void bubbleSort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void displaySorted(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
	
int main(){
	
	int arr[5] = {29, 3, 10, 45, 11};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr, size);
	displaySorted(arr, size);
	
	return 0;
}
