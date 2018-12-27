# Binary Tree

A Binary Tree is a non-linear(hierarchichal) data structure. Binary means that every element can have at most two elements attached to it. 

## Terminology

1. A node having an edge to other nodes below it is called **parent**
2. The nodes having an edge to a node directly above them are called **children**
3. The top most node of the tree is called **root**
4. The nodes at the bottom of the tree that have no children are called **leaves**

## Why trees?
1. To represent hierarchies
2. For more effiecient access/search/insertion/deletion than arrays and linked lists

## Operations (in linked list)

### Insert
```
Insert(root, key)
	Pre: root is the top most node of the tree
	     key is the value to be inserted
	Post: key inserted in the tree

	new = node(key)
	enqueue(root)
	while queue != ø
		temp = dequeue()
		if temp = ø
			root = new
			break
		end if
		if temp -> left != ø
			temp -> left = new
			break
		else
			enqueue(temp -> left)
		end if
		if temp -> right != ø
			temp -> right = new
			break
		else
			enqueue(temp -> right)
		end if
	end while
	
end Insert
```

### Search
```
Search(root, key)
	Pre: root is the top most node of the tree
	     key is the value to be searched
	Post: searched node, if found; ø otherwise

	enqueue(root)
	while queue != empty
		temp = dequeue()
		if temp != ø and temp -> key = key
			return temp
		if temp -> left != ø
			enqueue(temp -> left)
		if temp -> right != ø
			enqueu(etemp -> right)
	end while
	return ø
	
end Search
```

### Delete

1. Find the deepest and right most node
2. Find the node to be deleted
3. Swap value of to be deleted node and deepest and rightmost node
4. Delete the deepest and rightmost node

```
Delete(root, key)
	Pre: root is the top most node of the tree
	     key is the value to be deleted
	Post: key deleted from the tree
	
	if root -> key = key
		delete(root)
		return ø
	end if
	
	enqueue(root)
	dNode = ø
	temp = ø
	
	while queue != empty
		dNode = dequeue()
		if dNode -> key = key
			temp = dNode
		end if
		if dNode -> left != ø
			enqueue(dNode -> left)
		end if
		if dNode -> right != ø
			enqueue(dNode -> right)
		end if
	end while
	
	if temp != ø and dNode != ø
		temp -> key = dNode -> key
		DeleteDeepest(root, dNode)
	end if
	
end Delete
```
```
DeleteDeepest(root, dNode):
	Pre: root is the root node of tree
		 dNode is the deepest node
	Post: dNode is deleted from the tree

	enqueue(root)
	while queue != empty
		temp = dequeue()
		if temp -> left != ø
			if temp -> left = dNode
				delete(temp -> left)
				break
			else
				enqueue(temp -> left)
			end if
		end if
		if temp -> right != ø
			if temp -> right = dNode
				delete(temp -> left)
				break
			else
				enqueue(temp -> right)
			end if
		end if
	end while
	
end DeleteDeepest
```

## Traversals

### In-order

1. Visit left child
2. Visit root
3. Visit right child

```
  1
 / \
2   3
Result: 213
```

```
Inorder(temp)
	Pre: temp a node of tree (preferably root node)
	Post: Key of nodes printed in inorder fashion
	
	if temp != ø
		Inorder(temp -> left)
		display temp -> key
		Inorder(temp -> left)
	end if
	
end Inorder
```

### Pre-order

1. Visit root
2. Visit left child
3. Visit right child

```
  1
 / \
2   3
Result: 123
```

```
Preorder(temp)
	Pre: temp a node of tree (preferably root node)
	Post: Key of nodes printed in pre-order fashion
	
	if temp != ø
		display temp -> key
		Preorder(temp -> left)
		Preorder(temp -> left)
	end if
	
end Preorder
```
### Post-order

1. Visit left child
2. Visit right child
3. Visit root

```
  1
 / \
2   3
Result: 231
```

```
Postorder(temp)
	Pre: temp a node of tree (preferably root node)
	Post: Key of nodes printed in post-order fashion
	
	if temp != ø
		Postorder(temp -> left)
		Postorder(temp -> left)
		display temp -> key
	end if
	
end Postorder
```


## Complexities

### Time complexity

| Search     | Insertion | Deletion  |
| :--------: |:--------: |:--------: |
| O(n)       | O(n)      | O(n)      |

### Space complexity
O(n)

## Resources
[GeeksForGeeks](https://www.geeksforgeeks.org)
[Carnegie Mellon University](http://cs.cmu.edu)