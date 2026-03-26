#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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

void bubbleSort(arrSort *a){
	for(int i = 0; i < a->count; i++){
		for(int j = 0; j < a->count - i; j++){
			if(a->data[j] > a->data[j + 1]){
				int temp = a->data[j];
				a->data[j] = a->data[j + 1];
				a->data[j + 1] = temp;
			}
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
	
	printf("Unsorted arr:\n");
	for(int i = 0; i < 5; i++){
		printf("%d ", arr.data[i]);
	}
	bubbleSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);
	
	return 0;
}
