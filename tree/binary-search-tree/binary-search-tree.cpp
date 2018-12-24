#include <iostream>
#include <stdlib.h>
using namespace std;

// Node structure for tree
struct Node{
	int key;
	struct Node * left;
	struct Node * right;
};

// Insert new node to binary search tree
int insert(struct Node ** root, int key){

	if(*root == NULL){
		// No node present
		// Add new node
		struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->key = key;
		*root = new_node;
		return true;
	}else if (key < (*root)->key)
		// Key less than node's key
		return insert(&((*root)->left), key);
	else if (key > (*root)->key)
		// Key greater than node's key
		return insert(&((*root)->right), key);
	else if ((*root)->key == key)
		// Key already exists
		return false;
}

// Search for a node
struct Node * search(struct Node * root, int key){
	if(root == NULL)
		// Not found
		return NULL;
	else if(root->key == key)
		// Found
		return root;
	else if(key < root->key)
		// Not found; key less than current node's key
		return search(root->left, key);
	else if(key > root->key)
		// Not found; key greater than current node's key
		return search(root->right, key);
}

// Find min value node in a bst
struct Node * minValueNode(struct Node * root){
	if(root->left == NULL)
		return root;
	else
		return minValueNode(root->left);
}

// Delete a node
int delete_node(struct Node ** root, int key){
	if (*root == NULL)
		return false;
	else if((*root)->key == key){
		// Delete node
		if((*root)->left == NULL && (*root)->right == NULL){
			// Node is a leaf
			free(*root);
			*root = NULL;
		}else if((*root)->left != NULL && (*root)->right == NULL){
			// Node has only left child
			struct Node * temp = (*root)->left;
			free(*root);
			(*root) = temp;
		}else if((*root)->left == NULL && (*root)->right != NULL){
			// Node has only right child
			struct Node * temp = (*root)->right;
			free(*root);
			(*root) = temp;
		}else{
			// Node has both left and right child
			struct Node * min = minValueNode((*root)->right);
			(*root)->key = min->key;
			free(min);
		}
		return true;
	}else if(key < (*root)->key)
		return delete_node(&(*root)->left, key);
	else if(key > (*root)->key)
		return delete_node(&(*root)->right, key);
}

// Inorder Traversal
void inOrderTraverse(struct Node * root){
	if(root != NULL){
		inOrderTraverse(root->left);
		cout << root->key;
		inOrderTraverse(root->right);
	}
}

int main(){

	// Pointer to first node of binary search tree
	struct Node * root = NULL;
	// Temporary pointer
	struct Node * temp = NULL;

	// make request and store sucess code for each 
	// insert operation
	int res;
	res = insert(&root, 5);
	res = insert(&root, 2);
	res = insert(&root, 3);
	res = insert(&root, 4);
	res = insert(&root, 7);
	res = insert(&root, 6);
	res = insert(&root, 8);

	// Traversal
	inOrderTraverse(root);
	cout << '\n';

	// Search
	temp = search(root, 8);
	if(temp != NULL)
		cout << "FOUND" << '\n';
	else
		cout << "NOT FOUND" << '\n';

	temp = search(root, 10);
	if(temp != NULL)
		cout << "FOUND" << '\n';
	else
		cout << "NOT FOUND" << '\n';

	// Deletion
	res = delete_node(&root, 8);
	if(res)
		cout << "DELETED" << '\n';
	else
		cout << "COULD NOT BE DELETED" << '\n';

	res = delete_node(&root, 8);
	if(res)
		cout << "DELETED" << '\n';
	else
		cout << "COULD NOT BE DELETED" << '\n';

	return 0;
}