#include "heap.hpp"

// A utility function to print array elements
void printArray(int arr[], int size);

void changeValues (int *a, int *b);

void permutation (int arr[], int n );

// C++ function to find inverse permutations with a O(N^2) algorithm
void inversePON2(int* arr1, int* arr2, int size);

/*Divides the segments arr1[l … l+N−1] and arr2[l … l+N−1] into K equal subarrays.
It dynamically allocates memory for these subarrays and copies the elements so that the element at 
position m  of the i-th subarray corresponds to arr2d1[i][m] and arr2d2[i][m], preserving the 
original pairing between arr1 and arr2. */
void buildSubArrays(int* arr1, int* arr2, int l, int N, int K, int**& arr2d1, int**& arr2d2, int& NJ);

/*Merges the K sorted subarrays into a single sorted segment using a min-heap, keeping paired elements synchronized. */
void mergeWithHeap(int* arr1, int* arr2, int l, int N, int K, int NJ, int** arr2d1, int** arr2d2);

/*Releases all dynamically allocated memory used by the subarrays to prevent memory leaks.*/
void freeSubArrays(int** arr2d1, int** arr2d2, int K);

/*Merges K sorted subarrays contained in the range arr1[l … r] into a single sorted segment using a min-heap, 
while keeping the corresponding elements of arr2 aligned with their associated values in arr1.*/
void mergeKArrays(int* arr1, int* arr2, int l, int r, int K);


/*Recursively divides the array range into K equal segments, sorts each segment independently, 
and then merges the K sorted segments into a single sorted range using a K-way merge.*/
void mergeKSort(int* array1, int* array2, int l, int r, int k);

void inverseMergeK(int* arr1, int* arr2, int size, int k);
