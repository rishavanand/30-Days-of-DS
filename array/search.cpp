#include <iostream>
using namespace std;

// This function returns only the first occurance of the element in array

int search(int arr[], int n, int s){

	// Declare and initialize a variable i to first index of the array
	int i = 0;

	// For all the elements of the array
	while(i<n){
		// If value at index i equals search element return index i
		if(arr[i] == s)
			return i;
		i++;
	}
	// If search element not in array then return -1
	return -1;
}

int main(){

	int arr[] = {3,7,4,6,1,0};
	int search_value, result, n;

	// Calculate number of elements in array
	n = sizeof(arr)/sizeof(int);

	// Get value at specified index
	search_value = 6;
	result = search(arr, n, search_value);

	// Display result
	if(result == -1)
		cout << "Element not found" << endl;
	else
		cout << "Element found at index: " << result << endl;

	return 0;
}