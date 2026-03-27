#include <stdio.h>
#define MAX 5
typedef struct node{
	int data[MAX];
	int count;
}arrSort;

void initArr(arrSort *a){
	a->count = -1;
}

void insertFirst(arrSort *a, int val){
	if(a->count < MAX){
		for(int i = a->count; i >= 0; i--){
			a->data[i + 1] = a->data[i];
		}
		a->data[0] = val;
		a->count++;
	}
}

void bucketSort(arrSort *a){
	int max = a->data[0];
	for(int i = 0; i < a->count + 1; i++){
		if(max < a->data[i]){
			max = a->data[i];
		}
	}
	
	int bucket[10][a->count + 1];
	int bucketCount[10];
	for(int i = 0; i < 10; i++){
		bucketCount[i] = 0;
	}
	
	for(int i = 0; i < a->count + 1; i++){
		int bIdx = (a->data[i] * 9) / max;
		bucket[bIdx][bucketCount[bIdx]] = a->data[i];
		bucketCount[bIdx]++;
	}
	
	for(int i = 0; i < 10; i++){
		int count = bucketCount[i];
		for(int j = 0; j < a->count - 1; j++){
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
		for(int j = 0; j < bucketCount[i]; j++){
			a->data[idx] = bucket[i][j	];
			idx++;
		}
	}
}

void displaySorted(arrSort a){
	int i;
	for(i = 0; i <= a.count; i++){
		printf("%d ", a.data[i]);
	}
}

int main(){

	arrSort arr;
	initArr(&arr);

	insertFirst(&arr, 5);
	insertFirst(&arr, 2);
	insertFirst(&arr, 100);
	insertFirst(&arr, 30);
	insertFirst(&arr, 19);

	printf("count val: %d\n", arr.count);

	printf("Unsorted arr:\n");
	for(int i = 0; i < arr.count + 1; i++){
		printf("%d ", arr.data[i]);
	}
	bucketSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);

}
