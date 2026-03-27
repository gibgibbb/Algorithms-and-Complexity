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

void countingSort(arrSort *a){
	int max = a->data[0];
	for(int i = 0; i < a->count; i++){
		if(max < a->data[i]){
			max = a->data[i];
		}
	}
	int count[max + 1];
	int output[a->count];
	
	for(int i = 0; i <= max; i++){
		count[i] = 0;
	}

	for(int i = 0; i < a->count; i++){
		count[a->data[i]]++;
	}
	
	for(int i = 1; i <= max; i++){
		count[i] += count[i - 1];
	}
	
	for(int i = a->count - 1; i >= 0; i--){
		output[count[a->data[i]] - 1] = a->data[i];
		count[a->data[i]]--;
	}
	
	for(int i = 0; i < a->count; i++){
		a->data[i] = output[i];
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
	countingSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);

}
