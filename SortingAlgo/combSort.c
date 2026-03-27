#include <stdio.h>

void combSort(int arr[], int size){
	int gap = size;
	int swapped = 1;
	for(; gap != 1 || swapped != 0; ){
		gap = (gap * 10) / 13; // approx for dividing to 1.3
		if(gap < 1){
			gap = 1;
		}
		swapped = 0;
		for(int i = 0; i < size - gap; i++){
			if(arr[i] > arr[i + gap]){
				int temp = arr[i];
				arr[i] = arr[gap + i];
				arr[gap + i] = temp;
				swapped = 1;
			}
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
	combSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
