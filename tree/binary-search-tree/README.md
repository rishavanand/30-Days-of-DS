# Binary Search Tree

A Binary Search Tree is a non-linear(hierarchichal) data structure. In this variant of Binary Tree, the left child is always less than the nodes above it and the right child is always greater than the nodes above it. The deepest and leftmost node is the smallest (by value) and the deepest and the rightmost node is the largest (by value).

## Why Binary Search Trees?
1. In average cases the access/search/insertion/deletion operation time reduces to O(log(n)) with respect to O(n) of a Binary Tree.

## Operations (in linked list)

### Insert
```
Insert(root, key)
	Pre: root is the top node of a tree
	     key is the value to be inserted
	Post: key inserted in the tree

	if root = ø
		new = node(key)
		root = node
		return true
	else if key < root -> left
		return Insert(root -> left, key)
	else if key > root -> right
		return Insert(root-> right, key)
	else
		return false
	end if
	
end Insert
```

### Search
```
Search(root, key)
	Pre: root is the top node of a tree
	     key is the value to be search
	Post: searched node, if found; ø otherwise

	if root = ø
		return false
	end if root -> key = key
		return true
	else if key < root -> left
		return Search(root -> left, key)
	else
		return Search(root -> right, key)

end Search
```

### Delete

#### If node to be deleated is a leaf
1. Delete it

#### If node to be deleted has only one child
1. Replace the node to be deleted with that of the child
2. Delete the node to be deleted

#### If node to be deleted has both children
1. Find the node successive to it in in-order traversal 
2. Swap both the nodes
3. Delete the successive node

```
Delete(root, key)
	Pre: root is the top node of a tree
	     key is the value to be deleted
	Post: key deleted in the tree
	
	if root = ø
		return false
	else if root -> key = key
		if root -> left = ø and root -> right = ø
			free(root)
		else if root -> left != ø and root -> right = ø
			temp = root -> left
			free(root)
			root = temp
		else if root -> left = ø and root -> right != ø
			temp = root -> right
			free(root)
			root = temp
		else
			min = minValueNode(root)
			free(root)
			root = min
		end if
		return true
	else if key < root -> key
		return Delete(root -> left, key)
	else if right > root -> key
		return Delete(root -> right, key)
	end if 
	
end Delete
```
```
minValueNode(root):
	Pre: root is the top node of a tree
	Post: node with least value is returned

	if root -> left = ø
		return root
	else
		return minValueNode(root -> left)
	
end minValueNode
```

## Complexities

### Time complexity

#### Average case

| Search     | Insertion | Deletion  |
| :--------: |:--------: |:--------: |
| O(log(n))  | O(log(n)) | O(log(n)) |

#### Worst case

| Search     | Insertion | Deletion  |
| :--------: |:--------: |:--------: |
| O(n)       | O(n)      | O(n)      |

### Space complexity
O(n)

## Resources
[GeeksForGeeks](https://www.geeksforgeeks.org)