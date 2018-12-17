# Stack
A Stack is a linear data structure built on top of an array or a linked list. Stack consists of two unique operations:

 1. push() - inserts a new element to the last of the stack
 2. pop() - removes the last element from the stack

It follows the LIFO(last in first out) order. Meaning the last inserted element will be removed first. Some implementation are:

 1. Re-opening last closed tab in a browser
 2. Back/Forward functionality of a browser
 3. Recursive function calling feature provided by the OS

## Operations (in linked list)

### Push
```
Push(head, value)
	Pre: head is pointer to the first node of the reverse-list
	     value is the value to be inserted
	Post: value placed at the start of the reverse-list
	new = node(value)
	if head = ø
		head = new
	else
		new -> next = head
		head = new
	end if
end Push
```

### Pop
```
Pop(head)
	Pre: head is pointer to the first node of the reverse-list
	Post: first element of the reverse-list is removed
	if head != ø
		head = head -> next
	end if
end Pop
```

## Complexities

### Time complexity

| Push    | Pop    |
| :-----: | :----: |
| O(1)    | O(1)   |

### Space complexity
O(n)