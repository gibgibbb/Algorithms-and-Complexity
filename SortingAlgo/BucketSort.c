#include <stdio.h>

void bucketSort(int arr[], int size){
	int max = arr[0];
	for(int i = 0; i < size; i++){
		if(max < arr[i]){
			max = arr[i];
		}
	}
	
	int bucket[10][size];
	int bucketCount[10];
	for(int i = 0; i < 10; i++){
		bucketCount[i] = 0;
	}
	
	for(int i = 0; i < size; i++){
		int bIdx = (arr[i] * 9) / max;
		bucket[bIdx][bucketCount[bIdx]] = arr[i];
		bucketCount[bIdx]++;
	}
	
	for(int i = 0; i < 10; i++){
		int count = bucketCount[i];
		for(int j = 0; j < count - 1; j++){
			for(int k = 0; k < count - j - 1; k++){
				if(bucket[i][k] > bucket[i][k + 1]){
					int temp = bucket[i][k];
					bucket[i][k] = bucket[i][k + 1];
					bucket[i][k + 1] = temp;
				}
			}
		}
	}
	int idx = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; i < bucketCount[j]; j++){
			arr[idx] = bucketCount[j];
			idx++;
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

	bucketSort(arr, size);
	displaySorted(arr, size);

	return 0;
}
