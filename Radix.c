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

void insertLast(nodePtr *A, nodePtr temp){
    nodePtr *trav;
    for(trav = A; *trav != NULL; trav = &(*trav)->next){}
    temp->next = NULL;
    *trav = temp;
}

void radixSort(nodePtr *A){
	
 	int max = (*A)->data;
 	nodePtr trav = *A;
	for(; trav != NULL; trav = trav->next){
		if(trav->data > max){
			max = (*A)->data;
		}
	}
	
	for(int exp = 1; max / exp > 0; exp *= 10){
		nodePtr buckets[10];
		for(int i = 0; i < 10; i++){
			init(&buckets[i]);
		}

		nodePtr curr = *A;
		for(; curr != NULL; ){
    		nodePtr temp = curr;
    		curr = curr->next;

    		int digit = (temp->data / exp) % 10;
    		insertLast(&buckets[digit], temp);
		}
		
		*A = NULL;
		nodePtr *rebuild = A;
		for(int i = 0; i < 10; i++){
			if(buckets[i] != NULL){
				*rebuild = buckets[i];
				for(; (*rebuild)->next != NULL; rebuild = &(*rebuild)->next){}
				rebuild = &(*rebuild)->next;
			}
		}

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
    
    printf("Not Sorted:\n");
    displayList(main);
    
    printf("\nRadix Sorted:\n");
    radixSort(&main);
    displayList(main);
    
    return 0;
}
