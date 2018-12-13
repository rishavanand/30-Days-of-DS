#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node * next;
};

// This function adds node at the tail of the list
int insert(struct Node ** head, int value){
	if(*head == NULL){
		// Create new node
		struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->value = value;
		new_node->next = NULL;
		// Assign it to head
		*head = new_node;
	}else{
		// Traverse till the last node
		struct Node * temp = *head;
		while(temp->next != NULL)
			temp = temp->next;
		// Create new node
		struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->value = value;
		new_node->next = NULL;
		// Place it after the last node
		temp->next = new_node;
	}
}

// Prints value of each node
void traverse(struct Node * temp_head){
	// Keep traversing till the last node
	while(temp_head != NULL){
		cout << temp_head->value << " ";
		temp_head = temp_head->next;
	}
	cout << endl;
}

// Searches for a value in the list
int search(struct Node * temp_head, int value){
	while(temp_head != NULL){
		if(temp_head->value == value)
			return 1;
		else
			temp_head = temp_head->next;
	}
	return 0;
}

// Returns value of a node at specified index
struct Node * access(struct Node * temp_head, int index){
	int counter;
	counter = 0;
	while(counter >= 0 && counter <= index && temp_head != NULL){
		temp_head = temp_head->next;
		counter++;
	}
	if(temp_head == NULL || counter < 0)
		return NULL;
	else
		return temp_head;
}

// Deletes a node with specified value
int delete_node(struct Node ** head, int value){
	struct Node * temp_head = *head;
	if(temp_head != NULL && temp_head->value == value){
		*head = temp_head->next;
		return 1;
	}else{
		struct Node * prev_node = NULL;
		while(temp_head != NULL){
			if(temp_head->value == value){
				prev_node->next = temp_head->next;
				free(temp_head);
				return 1;
			}else{
				prev_node = temp_head;
				temp_head = temp_head->next;
			}
		}
		return 0;
	}
}

int main(){
	// Create a pointer to point to the first node
	struct Node * head = NULL;

	// Inserting
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);

	// Traversing
	traverse(head);

	// Searching
	int search_result;
	search_result = search(head, 7);
	(search_result == 0) ? cout << "Not found\n" : cout << "Found\n";

	// Accessing
	struct Node * access_result = access(head, 2);
	(access_result == NULL) ? cout << "Not found\n" : cout << access_result->value << endl;

	// Deletion
	int delete_result;
	delete_result = delete_node(&head, 7);
	(delete_result == 0) ? cout << "Could not be deleted\n" : cout << "Deleted\n";

	// Traversing to see nodes after deletion
	traverse(head);

	return 0;
}