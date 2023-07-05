#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

node* createNode(int value) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->value = value;
	ptr->next = NULL;
	return ptr;
}

int main() {

	node array;
	return 0;
}
