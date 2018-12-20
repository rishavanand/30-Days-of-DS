#include <iostream>
#include <stdlib.h>
using namespace std;

// Node structure for tree
struct tNode{
	int key;
	struct tNode * left;
	struct tNode * right;
};

// Node structure for queue
struct Node{
	struct tNode * keyNode;
	struct Node * next;
};

// Adds a node to the end of the queue
void enqueue(struct Node ** front, struct Node ** rear, struct tNode * tree_node){

	// Create node
	struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->keyNode = tree_node;
	new_node->next = NULL;

	if(*front == NULL){
		// No nodes in the queue
		*front = new_node;
		*rear = new_node;
	}else{
		// Some nodes in the queue
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

// Removes first element of the queue and returns its value
struct Node * dequeue(struct Node ** front, struct Node ** rear){

	if(*front == NULL)
		// Queue is empty
		return NULL;
	else if(*front == *rear){
		// Queue has only 1 node
		struct Node * temp = *front;
		*front = NULL;
		*rear = NULL;
		return temp;
	}else{
		// Queue has more that 1 node
		struct Node * temp = *front;
		*front = (*front)->next;
		return temp;
	}
}

// Tells if queue is empty
int queueIsEmpty(struct Node * front){
	if(front == NULL)
		// 0 nodes
		return 1;
	else
		// > 0 nodes
		return 0;
}

// Insert new node in tree
void insert(struct tNode ** root, int key){

	// Create new node
	struct tNode * new_node = (struct tNode *)malloc(sizeof(struct tNode));
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;

	if (*root == NULL){
		// Tree is empty
		*root = new_node;
		return;
	}else{
		// Tree is not empty

		// Pointers for implementing queue
		struct Node * front = NULL;
		struct Node * rear = NULL;
		struct Node * temp = NULL;
		struct tNode * treeTempNode = NULL;

		// Add root to queue
		enqueue(&front, &rear, *root);

		while(!queueIsEmpty(front)){
			temp = dequeue(&front, &rear);
			treeTempNode = temp->keyNode;

			if(treeTempNode->left == NULL){
				// Has to left child
				// Add new node to the left
				treeTempNode->left = new_node;
				return;
			}else{
				// Has a left child
				// Add left child to queue
				enqueue(&front, &rear, treeTempNode->left);
			}

			if(treeTempNode->right == NULL){
				// Has to left child
				// Add new node to the right
				treeTempNode->right = new_node;
				return;
			}else{
				// Has a right child
				// Add right child to queue
				enqueue(&front, &rear, treeTempNode->right);
			}
		}
	}
}

// Deletes deepest node
void deleteDeepest(struct tNode ** root, struct tNode * treeDeepNode){
	// Pointers for queue
	struct Node * front = NULL;
	struct Node * rear = NULL;
	struct Node * temp = NULL;
	struct tNode * tempTNode = NULL;

	if(*root == treeDeepNode){
		// Tree has only 1 node
		free(*root);
		*root = NULL;
		return;
	}

	enqueue(&front, &rear, *root);
	while(!queueIsEmpty(front)){
		temp = dequeue(&front, &rear);
		tempTNode = temp->keyNode;

		if(tempTNode->left != NULL){
			if(tempTNode->left == treeDeepNode){
				// Left child is the deepest node
				// Delete left child
				free(tempTNode->left);
				tempTNode->left = NULL;
				return;
			}else{
				// Left child is not the deepest node
				// Push it to queue
				enqueue(&front, &rear, tempTNode->left);
			}
		}

		if(tempTNode->right != NULL){
			if(tempTNode->right == treeDeepNode){
				// Right child is the deepest node
				// Delete right child
				free(tempTNode->right);
				tempTNode->right = NULL;
				return;
			}else{
				// Right child is not the deepest node
				// Push it to queue
				enqueue(&front, &rear, tempTNode->right);
			}
		}
	}

}

// Delete specified node from tree
int deleteNode(struct tNode ** root, int key){
	// Pointers for queue
	struct Node * front = NULL;
	struct Node * rear = NULL;
	struct Node * temp = NULL;
	struct tNode * treeTempNode = NULL;
	struct tNode * treeDeepNode = NULL;

	if (*root == NULL){
		// Tree is empty
		return 0;
	}

	enqueue(&front, &rear, *root);
	while(!queueIsEmpty(front)){
		temp = dequeue(&front, &rear);
		treeDeepNode = temp->keyNode;

		if(treeDeepNode->key == key){
			// Node to be deleted
			treeTempNode = treeDeepNode;
		}

		if(treeDeepNode->left != NULL){
			// Left child is not empty
			// Push left child to queue
			enqueue(&front, &rear, treeDeepNode->left);
		}

		if(treeDeepNode->right != NULL){
			// Right child is not empty
			// Push right child to queue
			enqueue(&front, &rear, treeDeepNode->right);
		}
	}

	treeTempNode->key = treeDeepNode->key;
	deleteDeepest(root, treeDeepNode);
	return 1;
}

void inorderTraverse(struct tNode * root){
	if(root){
		inorderTraverse(root->left);
		cout << root->key;
		inorderTraverse(root->right);
	}
}

int main(){

	// Pointer for implementing binary tree
	struct tNode * root = NULL;

	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);

	inorderTraverse(root);
	cout << '\n';

	/* 
	    1
	   / \
	  2   3

	*/

	deleteNode(&root, 2);
	inorderTraverse(root);
	cout << '\n';

	/* 
	    1
	   / 
	  3   

	*/

	deleteNode(&root, 1);
	inorderTraverse(root);
	cout << '\n';

	/* 
	    3
	     
	*/

	deleteNode(&root, 3);
	inorderTraverse(root);
	cout << '\n';

	/*

	*/

	return 0;
}