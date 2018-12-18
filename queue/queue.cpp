#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node * next;
};

// Adds a node to the end of the queue
void enqueue(struct Node ** front, struct Node ** rear, int value){
	struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->next = NULL;
	new_node->value = value;
	// if first node
	if(*front == NULL){
		*front = new_node;
		*rear = new_node;
	}else{
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

// Removes first element of the queue and returns its value
struct Node * dequeue(struct Node ** front, struct Node ** rear){
	if(*front == NULL)
		return NULL;
	else if(*front == *rear){
		struct Node * temp = *front;
		*front = NULL;
		*rear = NULL;
		return temp;
	}else{
		struct Node * temp = *front;
		*front = (*front)->next;
		return temp;
	}
}

int main(){
	// Create a pointer to for pointing to the first and last node
	struct Node * front = NULL;
	struct Node * rear = NULL;
	// Create temp pointer
	struct Node * temp = NULL;

	// Dequeue
	temp = dequeue(&front, &rear);
	if(temp != NULL)
		cout << temp->value << endl;
	else
		cout << "QUEUE IS EMPTY" << endl;

	// Enqueue
	enqueue(&front, &rear, 5);
	enqueue(&front, &rear, 6);
	enqueue(&front, &rear, 7);

	// Dequeue
	temp = dequeue(&front, &rear);
	if(temp != NULL)
		cout << temp->value << endl;
	temp = dequeue(&front, &rear);
	if(temp != NULL)
		cout << temp->value << endl;
	temp = dequeue(&front, &rear);
	if(temp != NULL)
		cout << temp->value << endl;
	temp = dequeue(&front, &rear);
	if(temp != NULL)
		cout << temp->value << endl;
	else
		cout << "QUEUE IS EMPTY" << endl;

	return 0;
}