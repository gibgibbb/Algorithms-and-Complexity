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

void insertionSort(arrSort *a){
	for(int i = 1; i < a->count + 1; i++){
		int key = a->data[i];
		int j;
		for(j = i - 1; j >= 0 && a->data[j] > key; j--){
			a->data[j + 1] = a->data[j];
		}
		a->data[j + 1] = key;
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
	for(int i = 0; i < arr.count; i++){
		printf("%d ", arr.data[i]);
	}
	insertionSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);
	
}
