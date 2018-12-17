# Quque
A Stack is another linear data structure built on top of an array or a linked list. It follows the FIFO(first in first out) order, meaning the least recently added element is removed first.  it consists of two unique operations:

 1. enqueue() - inserts a new element to the end of the queue
 2. dequeue() - removes the first element from the queue

Some example are:

 1. Process scheduling: Simplest being FCFS(first in first out ) scheduling where the process first to enter is served first.
 2. In real world: People standing in a queue outside an Apple store. First to arrive is the first to get the new product.

## Operations (in linked list)

### Enqueue
```
Enqueue(front, rear, value)
	Pre: front is pointer to the first element of the queue
	     rear is pointer to the last element of the queue
	     value is the value to be inserted
	Post: value placed at the end of the queue
	new = node(value)
	if rear = ø
		front = new
		rear = new
	else
		rear -> next = new
		rear = new
	end if
end Enqueue
```

### Dequeue
```
Dequeue(front, rear)
	Pre: front is pointer to the first element of the queue
	     rear is pointer to the last element of the queue
	Post: first element of the list is removed and returned
	if front = ø
		return ø
	else if front = rear
		temp = front
		front = ø
		rear = ø
		return temp
	else
		temp = front
		front = front -> next
		return temp
	end if
end Dequeue
```

## Complexities

### Time complexity

| Enqueue    | Dequeue    |
| :--------: | :--------: |
| O(1)       | O(1)       |

### Space complexity
O(n)
