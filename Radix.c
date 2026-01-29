#include <stdio.h>

typedef struct {
    int data;
    struct node *next;
}node, *nodePtr;

void init(node *A){
    A->next = NULL;
}

int main() {

    nodePtr main;
    init(main);
    
    return 0;
}
