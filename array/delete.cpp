#include <iostream>
using namespace std;

// This function deletes only the first occurance of the element in array

int delete_elem(int arr[], int n, int p){

	// Check if specified index is within the size of array
	if(p >= n){
		// Failure
		return 0;
	}else{
		// Shift all elements from index p+1 to n to the left
		while(p < n){
			arr[p] = arr[p+1];
			p++;
		}
		// Success
		return 1;
	}
}

int main(){

	int arr[] = {3,7,4,6,1,0};
	int delete_index, result, n;

	// Calculate number of elements in array
	n = sizeof(arr)/sizeof(int);

	// Specify index of element to be deleted
	delete_index = 3;

	// Delete
	result = delete_elem(arr, n, delete_index);

	// Check result
	if(result){
		n = n-1;
		cout << "Element deleted" << endl;
		cout << "New array is : " << endl;
		for(int i=0;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}else{
		cout << "Element could not be deleted" << endl;
	}

	return 0;
}