

# Linked List
A linked list a linear data structure where each element is a separate object and points to the next element. It is non-contiguous in nature that means the next element can reside anywhere in the memory. 

## Linked List over Array

### Advantages

- Dynamic size
	- Size of array is fixed but in linked list new elements can be inserted as long as it is allowed by the operation system.
 - Ease of insertion and deletion
	 - Elements can be inserted and deleted without needing to shift elements.

### Disadvantages

- Random access now allowed
- Memory overhead for storing of pointer to next element
- Not cache friendly
	- Since the elements are not contiguous, the probablity of next element being in the cache is low.

## Terminology

- Each element is called a **node**.
- Each node consists of **data elements**
- Each node also consists of a **pointer** to the next node called **next**.
- The first node is pointed by a pointer called **head**
- The last node is pointed by a pointer called **tail**

## Operations

### Access
```
Access(head, value)
	Pre: head is pointer to the first node
	     value is the value to access
	Post: pointer to node, if found; null, otherweise
	temp = head
	while temp != ø
		if temp -> value = value
			return true
		else
			temp = temp -> next
		end if
	end while
	return null
end Access
```

### Search
```
Search(head, value)
	Pre: head is pointer to the first node
	     value is the value to search for
	Post: true, if found; false, otherweise
	temp = head
	while temp != ø
		if temp -> value = value
			return true
		else
			temp = temp -> next
		end if
	end while
	return false
end Search
```
### Traverse
```
Traverse(head)
	Pre: head is pointer to the first node
	Post: pointer to node, if found; null, otherweise
	temp = head
	while temp != ø
		yeild temp -> value
		temp = temp -> next
	end while
end Traverse
```

### Insert (at the end)
```
Insert(head, value)
	Pre: head is pointer to the first node
	     value is the value to be inserted
	Post: value placed at the end of the list
	temp = head
	new = node(value)
	if temp = ø
		head = new
	else
		while temp -> next != ø
			temp = temp -> next
		temp -> next = new
	end if
end Insert
```
### Delete
```
Delete(head, value)
	Pre: head is pointer to the first node
	     value is the value to be deleted
	Post: true, if value is present and gets deleted; false, otherwise
	if head -> value = value
		head = head -> next
		return true
	else
		temp = head
		prev = ø
		while temp != ø
			if temp -> value = value
				prev -> next = temp -> next
				return true
			prev = temp
			temp = temp -> next
		end while
		return false
	end if
end Delete
```
## Complexities

### Time complexity

| Access    | Search    | Insertion | Deletion  |
| :-------: | :-------: | :-------: | :-------: |
| O(n)      | O(n)      | O(1)      | O(1)      |

**Insertion assumption:** the pointer is already pointing the location at which new value is to be inserted

**Deletion assumption:** the pointer is already pointing to the element which is to be deleted

### Space complexity
O(n)