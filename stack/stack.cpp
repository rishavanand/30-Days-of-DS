#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node * next;
};

// Adds a node to the starting of the reverse list
int push(struct Node ** head, int value){
	struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->value = value;
	// if first node
	if(*head == NULL){
		*head = new_node;
	}else{
		new_node->next = *head;
		*head = new_node;
	}
}

// Returns value of the first node of reverse list
struct Node * pop(struct Node ** head){
	struct Node * temp = *head;
	if(*head != NULL)
		*head = (*head)->next;
	return temp;
}

int main(){
	// Create a pointer to point to the first node
	struct Node * head = NULL;
	struct Node * temp = NULL;

	// Push
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);

	// Pop
	temp = pop(&head);
	if(temp != NULL)
		cout << temp->value << endl;
	temp = pop(&head);
	if(temp != NULL)
		cout << temp->value << endl;
	temp = pop(&head);
	if(temp != NULL)
		cout << temp->value << endl;


	return 0;
}