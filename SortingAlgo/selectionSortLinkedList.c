#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}*linkSort;

void init(linkSort *l){
	*l = NULL;
}

void selectionSortList(linkSort *l){
	for(linkSort *trav = l; *trav != NULL; trav = &(*trav)->next){
		linkSort *min = trav;
		for(linkSort *trav2 = &(*min)->next; *trav2 != NULL; trav2 = &(*trav2)->next){
			if((*trav2)->data < (*min)->data){
				min = trav2;
			}
		}
		if(min != trav){
			int temp = (*min)->data;
			(*min)->data = (*trav)->data;
			(*trav)->data = temp;
		}
	}
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
	printf("\nSorted:\n");
	selectionSortList(&list);
	displayList(list);

	return 0;
}
