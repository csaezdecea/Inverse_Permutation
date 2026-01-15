// C++ program to merge K sorted
// arrays of size N each.
#include <bits/stdc++.h>
using namespace std;


// A min-heap node
struct MinHeapNode {
	// The element to be stored
	int element;

	// index of the array from which the element is taken
	int i;

	// index of the next element to be picked from the array
	int j;
};

// Prototype of a utility function to swap two min-heap
// nodes
void swap(MinHeapNode* x, MinHeapNode* y);

// A class for Min Heap
class MinHeap {

	// pointer to array of elements in heap
	MinHeapNode* harr;

	// size of min heap
	int heap_size;

public:
	// Constructor: creates a min heap of given size
	MinHeap(MinHeapNode a[], int size);

	// to heapify a subtree with root at given index
	void MinHeapify(int);

	// to get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2 * i + 2); }

	// to get the root
	MinHeapNode getMin() { return harr[0]; }

	// to replace root with new node x and heapify() new
	// root
	void replaceMin(MinHeapNode x)
	{
		harr[0] = x;
		MinHeapify(0);
	}
};