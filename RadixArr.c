#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
	int data[MAX];
	int count;
}ListArr;

void init(ListArr *A){
	A->count = -1;
}

void insertLast(ListArr *A, int x){
	if(A->count < MAX){
		A->data[++A->count] = x;
	}
}

void display(ListArr A){
	int x;
	for(x = 0; x <= A.count; x++){
		printf("%d ", A.data[x]);
	}
}

void radixSort(ListArr *A){
	int max = A->data[0];
	for(int x = 0; x < A->count; x++){
		if(A->data[x] > max){
			max = A->data[x];
		}
	}
	for(int exp = 1; max / exp > 0; exp *= 10){

		ListArr buckets[10];
		for(int i = 0; i < 10; i++){
			buckets[i].count = -1;
		}

		for(int i = 0; i <= A->count; i++){
			// in this case, creating a variable "val" might seem like a waste of
			// space but it will actually save time because everytime we use
			// "A->data[i]" we access it plenty of times so creating a catcher var for
			// it will save time. idk if that makes sense
			int digit = (A->data[i] / exp) % 10;

			buckets[digit].count++;
			buckets[digit].data[buckets[digit].count] = A->data[i];
		}
		int ndx = 0;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j <= buckets[i].count; j++){
				A->data[ndx] = buckets[i].data[j];
				ndx++;
			}
		}
	}
}

int main (){
	
	ListArr R;
	init(&R);
	
	insertLast(&R, 2);
	insertLast(&R, 62);
	insertLast(&R, 135);
	insertLast(&R, 20);
	insertLast(&R, 104);
	
	display(R);
	printf("\n");
	radixSort(&R);
	display(R);
	
	return 0;
}
