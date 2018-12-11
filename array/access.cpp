#include <iostream>
using namespace std;

int access(int arr[], int p){
	// Return value at specified index
	return arr[p];
}

int main(){

	int arr[] = {3,7,4,6,1,0};
	int value, index;

	// Get value at specified index
	index = 3;
	value = access(arr, index);

	// Display value
	cout << "Value at index " << index << " is: " << value << endl;

	return 0;
}