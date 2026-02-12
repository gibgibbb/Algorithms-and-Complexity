#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[], int size);

void radixSort(int arr[], int size){
	int x;
	int max = arr[0];
	for(x = 1; x < size; x++){
		if(arr[x] > max){
			max = arr[x];
		}
	}

	for(int exp = 1; max / exp > 0; exp *= 10){
		int output[size];
		int count[10] = {0};

		for(x = 0; x < size; x++){
			int digit = (arr[x] / exp) % 10;
			count[digit]++;
		}

		for(x = 1; x < 10; x++){
			count[x] += count[x - 1];
		}

		for(x = size - 1; x >= 0; x--){
			int digit = (arr[x] / exp) % 10;
			output[count[digit] - 1] = arr[x];
			count[digit]--;
		}

		for(x = 0; x < size; x++){
			arr[x] = output[x];
		}
	}
}
int main(){
	

	
	int arr[10] = {21, 54, 3, 10, 12, 42, 39, 19, 75, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Unsorted\n");
	int x;
	for(x = 0; x < size; x++){
		printf("%d ", arr[x]);
	}
	
	radixSort(arr, size);
	printf("\nSorted\n");
	for(x = 0; x < size; x++){
		printf("%d ", arr[x]);
	}
	
	
	return 0;
}
