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
	int max = 0;
	for(int x = 0; x < (*sA).count; x++){
		if((*A).data[x] > max){
			max = (*A).data[x];
		}
	}
	for(int exp = 1; max / exp > 0; exp *= 10){
		ListArr bucket;
		for(int i = 0; i < 10)
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
	
	return 0;
}
