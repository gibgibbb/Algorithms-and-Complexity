#include <stdio.h>

void gnomeSort(int arr[], int size){
	for(int pos = 0; pos < size;){
		if(pos == 0 || arr[pos] >= arr[pos - 1]){
			pos++;
		} else {
			int temp = arr[pos];
			arr[pos] = arr[pos - 1];
			arr[pos - 1] = temp;
			pos--;
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
	gnomeSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
