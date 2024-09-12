#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int array[], int low, int high, int target) {
    // Base case: when the search interval is empty
    if (low > high) {
        return -1; // Target not found
    }

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // Check if the target is present at the middle index
    if (array[mid] == target) {
        return mid; // Target found at index mid
    }

    // If target is smaller than the middle element, search in the left half
    if (target < array[mid]) {
        return binarySearch(array, low, mid - 1, target);
    }

    // If target is larger than the middle element, search in the right half
    return binarySearch(array, mid + 1, high, target);
}

// Driver code
int main() {
    // Sample sorted array
    int data[20],size;
	
	cout<<"enter the size of data";
	cin>>size;
    for (int i=0;i<size;i++)
	{cin>>data[i];
	}

    int target;
    cout << "Enter the target value to search for: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(data, 0, size - 1, target);

    // Output the result
    if (result != -1) {
        cout << "Target found at index " << result << endl;
    } else {
        cout << "Target not found in the array" << endl;
    }

    return 0;
}
