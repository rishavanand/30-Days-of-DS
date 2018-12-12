

# Array

An array is a collection of homogeneous elements stored in contiguous memory locations. Address of the array is the address of the first element a.k.a base address and address of each element is given by:
`element address = base address + (size of a homogeneous element * index of element)`
This allows an element to be accessed directly without having to traverse the elements before it.

## Advantages
- Arrays are easy to implement
- Allows random access
- Each access operation is of complexity O(1)
- Has better cache locality
	- A chunk of memory is loaded into the cache memory upon first access and array elements are stored in contiguous memory locations, this means the probablity of future elements being in the cache memory is very high. This improves the performance significantly.

## Operations
### Access
```
Access(arr, p)
	Pre: arr is the array
	     p is position to be accessed
	Post: value at position p
	return arr[p]
end Access
```

### Search
```
Search(arr, n, s)
	Pre: arr is the array
	     n is size of the array
	     s in value to search
	Post: -1 if s not found in array; position, if found
	p = 1
	while p <= n:
		if arr[i] == s
			return p
		else 
			p = p+1
		end if
	end while
	return -1
end Search
```

### Insert
```
Insert(arr, n, s, v)
	Pre: arr is the array
	     n is maximum capacity of the array
	     s is current size of the array
	     v is value to be inserted
	Post: true, if value inserted into the array; false, if not
	if n < s
		arr[n] = v
		return true
	else
		return false
	end if
end Insert
```
### Delete
```
Delete(arr, n, p)
	Pre: arr is the array
	     n is size of the array
	     p is position of element to be deleted
	Post: true, if p is greater than n;false, otherwise
	if p > n
		return false
	else
		while i < n
			arr[p] = arr[p+1]
			p = p+1
		return true
		end while
	end if
end Delete
```
## Complexities
### Time complexity

| Access    | Search    | Insertion | Deletion  |
| :-------: | :-------: | :-------: | :-------: |
| O(1)      | O(n)      | O(n)      | O(n)      |

### Space complexity
O(n)