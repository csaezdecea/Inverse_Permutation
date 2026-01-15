#include "InversePerm.hpp"
#include <memory>


// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
    cout << endl;
}

void changeValues (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation (int arr1[], int n )
{
    //srand ( time(NULL) );
    srand(time(0));
    for (int i = n-1; i > 0; i--)
    {
        int rnd = rand();
        int j = rnd % (i+1);
        //std::cout << rnd << std::endl;
        /*if (rnd>pow(2,30)) {
            std::cout << rnd << std::endl;
            std::cout << (rnd > pow(2,30)) << std::endl;
        } */       
        changeValues(&arr1[i], &arr1[j]);
    }
}


// C++ function to find inverse permutations with a O(N^2) algorithm
void inversePON2(int* arr1, int* arr2, int size) {

  // Loop to select Elements one by one
  for (int i = 0; i < size; i++) {

    // Loop to print position of element
    // where we find an element
    for (int j = 0; j < size; j++) {

      // checking the element in increasing order
      if (arr1[j] == i + 1) {

        // print position of element where
        // element is in inverse permutation
        arr2[i] = j + 1;
        break;
      }
    }
  }
}


/*Divides the segments arr1[l … l+N−1] and arr2[l … l+N−1] into K equal subarrays.
It dynamically allocates memory for these subarrays and copies the elements so that the element at 
position m  of the i-th subarray corresponds to arr2d1[i][m] and arr2d2[i][m], preserving the 
original pairing between arr1 and arr2. */
void buildSubArrays(int* arr1, int* arr2, int l, int N, int K, int**& arr2d1, int**& arr2d2, int& NJ) {
    NJ = N / K;

    // Allocate the array of pointers
    arr2d1 = new int*[K];
    arr2d2 = new int*[K];

    // Allocate and fill each subarray
    for (int i = 0; i < K; i++) {
        arr2d1[i] = new int[NJ];
        arr2d2[i] = new int[NJ];

        for (int j = 0; j < NJ; j++) {
            arr2d1[i][j] = arr1[l + NJ * i + j];
            arr2d2[i][j] = arr2[l + NJ * i + j];
        }
    }
}


/*Merges the K sorted subarrays into a single sorted segment using a min-heap, keeping paired elements synchronized. */
void mergeWithHeap(int* arr1, int* arr2, int l, int N, int K, int NJ, int** arr2d1, int** arr2d2) {
    MinHeapNode* harr = new MinHeapNode[K];

    for (int i = 0; i < K; i++) {
        harr[i].element = arr2d1[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }

    MinHeap hp(harr, K);

    for (int count = l; count < l + N; count++) {
        MinHeapNode root = hp.getMin();

        arr1[count] = root.element;
        arr2[count] = arr2d2[root.i][root.j - 1];

        if (root.j < NJ) {
            root.element = arr2d1[root.i][root.j];
            root.j++;
        } else {
            root.element = INT_MAX;
        }

        hp.replaceMin(root);
    }

    delete[] harr;
}

/*Releases all dynamically allocated memory used by the subarrays to prevent memory leaks.*/
void freeSubArrays(int** arr2d1, int** arr2d2, int K) {
    for (int i = 0; i < K; i++) {
        delete[] arr2d1[i];
        delete[] arr2d2[i];
    }
    delete[] arr2d1;
    delete[] arr2d2;
}


/*Merges K sorted subarrays contained in the range arr1[l … r] into a single sorted segment using a min-heap, 
while keeping the corresponding elements of arr2 aligned with their associated values in arr1.*/
void mergeKArrays(int* arr1, int* arr2, int l, int r, int K) {
    int N = r - l + 1;
    int NJ;

    int** arr2d1;
    int** arr2d2;

    buildSubArrays(arr1, arr2, l, N, K, arr2d1, arr2d2, NJ);
    mergeWithHeap(arr1, arr2, l, N, K, NJ, arr2d1, arr2d2);
    freeSubArrays(arr2d1, arr2d2, K);
}


/*Recursively divides the array range into K equal segments, sorts each segment independently, 
and then merges the K sorted segments into a single sorted range using a K-way merge.*/
void mergeKSort(int *array1, int* array2, int l, int r, int k) {
   int m;
   if(l < r) {
      int step = (r-l+1)/k;
      // MergeKsort on the k division of the array
	  for (int i=0; i<k; i++) 
	      mergeKSort(array1, array2, l+step*i, l+step*(i+1)-1,k);
	  // Array merging
	  mergeKArrays(array1,array2, l, r, k);
   }
}


void inverseMergeK(int* arr1, int* arr2, int size, int k) {
    mergeKSort(arr1, arr2, 0, size-1, k);
}