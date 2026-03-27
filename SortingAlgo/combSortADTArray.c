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

void combSort(arrSort *a){
	int gap = a->count + 1;
	int swapped = 1;
	for(; gap != 1 || swapped != 0;){
		gap = (gap * 10) / 13;
		if(gap < 1){
			gap = 1;
		}
		swapped = 0;
		for(int i = 0; i < a->count + 1 - gap; i++){
			if(a->data[i] > a->data[i + gap]){
				int temp = a->data[i];
				a->data[i] = a->data[gap + i];
				a->data[gap + i] = temp;
				swapped = 1;
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

	printf("count val: %d\n", arr.count);

	printf("Unsorted arr:\n");
	for(int i = 0; i < arr.count + 1; i++){
		printf("%d ", arr.data[i]);
	}
	combSort(&arr);
	printf("\nSorted arr:\n");
	displaySorted(arr);

}
