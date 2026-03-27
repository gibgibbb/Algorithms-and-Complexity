#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}*linkSort;

void init(linkSort *l){
	*l = NULL;
}

void insertionSortList(linkSort *l){
	// cannot do this without using trailing pointers
}

void insertFirst(linkSort *l, int val){
	linkSort temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = val;
		temp->next = *l;
		*l = temp;
	}
}

void displayList(linkSort l){
	for(; l != NULL; l = l->next){
		printf("%d ", l->data);
	}
}

int main(){

	linkSort list;
	init(&list);

	insertFirst(&list, 20);
	insertFirst(&list, 54);
	insertFirst(&list, 321);
	insertFirst(&list, 5);
	insertFirst(&list, 10);

	printf("Unsorted:\n");
	displayList(list);
//	printf("\nSorted:\n");
//	insertionSortList(&list);
//	displayList(list);

	return 0;
}
