#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[], int x){
	int max = arr[0];
	
	for(int i = 0; i < x; i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}
	
	for(int exp = 1; max/exp > 0; exp *= 10){
		
		int output[x];
		int count[10] = {0};
		
		for(int i = 0; i < x; i++){
			int digit = (arr[i] / exp) % 10;
			count[digit]++;
		}
		
		for(int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}
		
		for(int i = x - 1; i >= 0; i--){
			int digit = (arr[i] / exp) % 10;
			output[count[digit] - 1] = arr[i];
			count[digit]--;
		}
		
		for(int i = 0; i < x; i++){
			arr[i] = output[i];
		}
	}
}

int main(){
	
	int arr[5] = {10, 21, 52, 100, 49};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	radixSort(arr, size);
	
	for(int i = 0; i < size; i++){
		printf("%x ", &arr[i]);
	}

	return 0;
}
