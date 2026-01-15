#include "InversePerm.hpp"
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

template <typename T, std::size_t N>
bool arrayEqualsVector(const T (&arr)[N], const std::vector<T>& vec)
{
    return vec.size() == N &&
           std::equal(arr, arr + N, vec.begin());
}
 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
    n=pow(2,4);
 
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }

    free(ptr);

    int K = 7;

    int arr[] = {10, 5, 20, 1, 8, 4, 12};

    
    std::vector<int> v = std::vector<int>(arr, arr + K);
    std::make_heap(v.begin(), v.end(), std::greater<int>());

    std::cout << "\nHeap: \n";    
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;


    MinHeapNode* harr = new MinHeapNode[K];

    for (int i = 0; i < K; i++) {
        harr[i].element = arr[i];
        harr[i].i = i;
        harr[i].j = 1;
    }

    MinHeap heap(harr, K);

    auto heapArray = heap.toVector();

    cout << "Heap 2: \n"; 
    for (const auto& node : heapArray) {
        cout << node.element << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < K; i++) arr[i] = heapArray[i].element;
    
    if (arrayEqualsVector(arr, v)) std::cout << "Test Heap1 successfull\n";
    else std::cout << "Test Heap1 unsuccessfull\n";

    MinHeapNode root = heap.getMin();
    std::cout << "Root value = " << root.element << "\n";

    root.element = 10;
    heap.replaceMin(root);
    heapArray = heap.toVector();
    for (int i = 0; i < K; i++) arr[i] = heapArray[i].element;
    
    v[0] = 10;
    std::make_heap(v.begin(), v.end(), std::greater<int>());

     if (arrayEqualsVector(arr, v)) std::cout << "Test Heap2 successfull\n";
    else std::cout << "Test Heap2 unsuccessfull\n";

    
    



    
 
    return 0;
}