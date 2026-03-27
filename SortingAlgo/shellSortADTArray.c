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

void shellSort(arrSort *a){
	for(int gap = a->count/2; gap != 0; gap /= 2){
		for(int i = gap; i < a->count + 1; i++){
			int temp = a->data[i];
			int j;
			for(j = i; j >= gap && a->data[j - gap] > temp; j-= gap){
				a->data[j] = a->data[j - gap];
			}
			a->data[j] = temp;
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
	shellSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);

}
