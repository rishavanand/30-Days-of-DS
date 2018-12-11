#include <iostream>
using namespace std;

// This function deletes only the first occurance of the element in array

int insert(int arr[], int n, int s, int v){

	// Check if size equals capacity
	if(s == n){
		// Failure
		return 0;
	}else{
		// Insert at the last 
		arr[s] = v;
		// Success
		return 1;
	}
}

int main(){

	int arr[10] = {3,7,4,6,1,0};
	int insert_value, result, capacity, current_size;

	// Calculate number of elements in array
	capacity = sizeof(arr)/sizeof(int);
	current_size = 6;

	// Specify index of element to be deleted
	insert_value = 8;

	// Insert
	result = insert(arr, capacity, current_size, insert_value);

	// Check result
	if(result){
		current_size = current_size+1;
		cout << "Element inserted" << endl;
		cout << "New array is : " << endl;
		for(int i=0;i<current_size;i++)
			cout << arr[i] << " ";
		cout << endl;
	}else{
		cout << "Element could not be inserted" << endl;
	}

	return 0;
}