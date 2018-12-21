#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

// Node structure for tree
struct tNode{
	int key;
	struct tNode * left;
	struct tNode * right;
};

// Insert new node in tree
void insert(struct tNode ** root, int key){

	queue<struct tNode *> q;

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

		struct tNode * treeTempNode = NULL;

		// Add root to queue
		q.push(*root);

		while(!q.empty()){
			treeTempNode = q.front();
			q.pop();

			if(treeTempNode->left == NULL){
				// Has to left child
				// Add new node to the left
				treeTempNode->left = new_node;
				return;
			}else{
				// Has a left child
				// Add left child to queue
				q.push(treeTempNode->left);
			}

			if(treeTempNode->right == NULL){
				// Has to left child
				// Add new node to the right
				treeTempNode->right = new_node;
				return;
			}else{
				// Has a right child
				// Add right child to queue
				q.push(treeTempNode->right);
			}
		}
	}
}

// Deletes deepest node
void deleteDeepest(struct tNode ** root, struct tNode * treeDeepNode){

	queue<struct tNode *> q;

	struct tNode * tempTNode = NULL;

	if(*root == treeDeepNode){
		// Tree has only 1 node
		free(*root);
		*root = NULL;
		return;
	}

	q.push(*root);
	while(!q.empty()){
		tempTNode = q.front();
		q.pop();

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
				q.push(tempTNode->left);
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
				q.push(tempTNode->right);
			}
		}
	}

}

// Delete specified node from tree
int deleteNode(struct tNode ** root, int key){
	
	queue<struct tNode *> q; 

	struct tNode * treeTempNode = NULL;
	struct tNode * treeDeepNode = NULL;

	if (*root == NULL){
		// Tree is empty
		return 0;
	}

	q.push(*root);
	while(!q.empty()){
		treeDeepNode = q.front();
		q.pop();

		if(treeDeepNode->key == key){
			// Node to be deleted
			treeTempNode = treeDeepNode;
		}

		if(treeDeepNode->left != NULL){
			// Left child is not empty
			// Push left child to queue
			q.push(treeDeepNode->left);
		}

		if(treeDeepNode->right != NULL){
			// Right child is not empty
			// Push right child to queue
			q.push(treeDeepNode->right);
		}
	}

	treeTempNode->key = treeDeepNode->key;
	deleteDeepest(root, treeDeepNode);
	return 1;
}

// Inorder Traversal
void inOrderTraverse(struct tNode * root){
	if(root){
		inOrderTraverse(root->left);
		cout << root->key;
		inOrderTraverse(root->right);
	}
}

// Pre-order Traversal
void preOrderTraverse(struct tNode * root){
	if(root){
		cout << root->key;
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

// Post-order Traversal
void postOrderTraverse(struct tNode * root){
	if(root){
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		cout << root->key;
	}
}

int main(){

	// Pointer for implementing binary tree
	struct tNode * root = NULL;

	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);

	inOrderTraverse(root);
	cout << '\n';

	/* 
	    1
	   / \
	  2   3

	*/

	deleteNode(&root, 2);
	inOrderTraverse(root);
	cout << '\n';

	/* 
	    1
	   / 
	  3   

	*/

	deleteNode(&root, 1);
	inOrderTraverse(root);
	cout << '\n';

	/* 
	    3
	     
	*/

	deleteNode(&root, 3);
	inOrderTraverse(root);
	cout << '\n';

	/*

	*/

	// Traversals

	insert(&root, 1);
	insert(&root, 2);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 5);
	insert(&root, 6);

	cout << "In-order: ";
	inOrderTraverse(root);
	cout << '\n';

	cout << "Pre-order: ";
	preOrderTraverse(root);
	cout << '\n';

	cout << "Post-order: ";
	postOrderTraverse(root);
	cout << '\n';

	return 0;
}