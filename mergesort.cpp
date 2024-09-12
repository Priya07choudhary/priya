#include<stdio.h>
#include <iostream>
using namespace std;


void merge(int array[], int left, int mid, int right) 
{ 
	// Create two auxiliary arrays 
	// to store elements of the left 
	// and right halves of the array 
	int leftSize = mid - left + 1; 
	int rightSize = right - mid; 
	int leftArray[leftSize], rightArray[rightSize]; 
	
	// Copy elements of the left half 
	// into the left auxiliary array 
	for (int i = 0; i < leftSize; i++) 
		leftArray[i] = array[left + i]; 
	
	// Copy elements of the right half 
	// into the right auxiliary array 
	for (int j = 0; j < rightSize; j++) 
		rightArray[j] = array[mid + 1 + j]; 
	
	// Merge the two halves 
	int i = 0, j = 0; 
	int k = left; 
	while (i < leftSize && j < rightSize) 
	{ 
		if (leftArray[i] <= rightArray[j]) 
			array[k++] = leftArray[i++]; 
		else
			array[k++] = rightArray[j++]; 
	} 
	
	// Copy remaining elements 
	while (i < leftSize) 
		array[k++] = leftArray[i++]; 
	
	while (j < rightSize) 
		array[k++] = rightArray[j++]; 
} 

// Function to divide the array 
// into two halves, sort each 
// half and merge them 
void mergeSort(int array[], int left, int right) 
{ 
	if (left < right) 
	{ 
		// Find the middle element 
		int mid = left + (right - left) / 2; 
	
		// Sort the left half 
		mergeSort(array, left, mid); 
	
		// Sort the right half 
		mergeSort(array, mid + 1, right); 
	
		// Merge the sorted halves 
		merge(array, left, mid, right); 
	} 
} 

// Function to print the array 
void printArray(int array[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << array[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	
	int array[10],size;
	cout<<"enter the size of array";
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>array[i];
	}
	// Print the array before sorting 
	cout << "Array before sorting: "; 
	printArray(array, size); 
	
	// Sort the array 
	mergeSort(array, 0, size - 1); 
	
	// Print the array after sorting 
	cout << "Array after sorting: "; 
	printArray(array, size); 
	
	return 0; 
} 
