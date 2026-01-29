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

void insertLast(nodePtr *A, nodePtr temp){
    if(*A == NULL){
        temp->next = NULL;
        *A = temp;
    } else {
        nodePtr trav;
        for(trav = *A; trav->next != NULL; trav = trav->next){}
        temp->next = NULL;
        trav->next = temp;
    }
}

void displayList(nodePtr A){
	for(; A != NULL; A = A->next){
		printf("%d ", A->data);
	}
}

int getMax(nodePtr A){
    int max = 0;
    for(; A != NULL; A = A->next){
        if(A->data > max){
            max = A->data;
        }
    }
    return max;
}

void radixSort(nodePtr *A){
    int max = getMax(*A);

    for(int exp = 1; max / exp > 0; exp *= 10){

        nodePtr bucket[10];
        for(int i = 0; i < 10; i++){
            bucket[i] = NULL;
        }

        nodePtr trav = *A;
        for(; trav != NULL; ){
            nodePtr temp = trav;
            trav = trav->next;

            int digit = (temp->data / exp) % 10;
            insertLast(&bucket[digit], temp);
        }

        *A = NULL;
        nodePtr *tail = A;

        for(int i = 0; i < 10; i++){
            if(bucket[i] != NULL){
                *tail = bucket[i];
                for(; (*tail)->next != NULL; tail = &(*tail)->next){}
                tail = &(*tail)->next;
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
    
    radixSort(&main);
    displayList(main);
    
    return 0;
}
