#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*nodePtr;

void init(nodePtr *A){
    *A = NULL;
}

void insertFirst(nodePtr *A, int x){
	nodePtr temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = x;
		temp->next = *A;
		*A = temp;
	}
}

void displayList(nodePtr A){
	for(; A != NULL; A = A->next){
		printf("%d ", A->data);
	}
}

int main() {

    nodePtr main;
    init(&main);
    insertFirst(&main, 10);
    insertFirst(&main, 5);
    insertFirst(&main, 500);
    insertFirst(&main, 39);
    insertFirst(&main, 259);
    
    displayList(main);
    
    return 0;
}
