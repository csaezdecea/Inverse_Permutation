# Inverse Permutation with K-Way Merge Sort

## Overview

This program generates and processes **permutations** and computes their **inverse permutation** using two different strategies:

1. A **naïve O(N²)** inverse permutation algorithm.
2. A **divide-and-conquer K-way merge–based algorithm** that sorts paired arrays using a min-heap.

Two arrays are kept **synchronized** throughout the program:

- `arr1`: stores values (typically a permutation).
- `arr2`: stores associated values (such as original indices).

Sorting `arr1` while preserving the pairing with `arr2` produces the inverse permutation.

---

## Utility Functions

### `printArray`

Prints the contents of an integer array to standard output.

### `changeValues`

Swaps two integers using pointers.

---

## Permutation Generation

### `permutation`

Implements the **Fisher–Yates shuffle** to generate a random permutation.

- Seeds the random number generator with the current time.
- Iterates backward through the array.
- Swaps each element with a randomly selected earlier position.
- Runs in **O(N)** time.

---

## Inverse Permutation (Naïve Method)

### `inversePON2`

Computes the inverse permutation using a brute-force **O(N²)** algorithm.

- For each value `i + 1`, scans the array to find its index.
- Stores the position (1-based) in the output array.
- Simple and correct, but inefficient for large inputs.

---

## Subarray Construction

### `buildSubArrays`

Splits contiguous segments of `arr1` and `arr2` into `K` equal-sized subarrays.

- Divides the range `[l, l + N - 1]` into `K` blocks of size `NJ = N / K`.
- Dynamically allocates two 2D arrays:
  - `arr2d1` for values from `arr1`
  - `arr2d2` for corresponding values from `arr2`
- Preserves the pairing between elements of `arr1` and `arr2`.

This step prepares the data for K-way merging.

---

## K-Way Merge Using a Min-Heap

### `mergeWithHeap`

Merges `K` sorted subarrays into a single sorted array segment.

- Uses a **min-heap** where each node tracks:
  - The current element value
  - The index of the subarray
  - The position within that subarray
- Repeatedly extracts the minimum element and inserts the next element from the same subarray.
- Ensures paired values in `arr2` remain aligned.
- Uses `INT_MAX` to mark exhausted subarrays.

**Time complexity:** `O(N log K)`

---

## Memory Management

### `freeSubArrays`

Releases all dynamically allocated memory used for subarrays, preventing memory leaks.

---

## Merge Coordination

### `mergeKArrays`

Manages the complete K-way merge process:

1. Splits the input arrays into `K` subarrays.
2. Merges them using a min-heap.
3. Frees all allocated memory.

Operates on the array range `[l, r]`.

---

## Recursive K-Way Merge Sort

### `mergeKSort`

Implements a **K-way merge sort** algorithm.

- Recursively divides the array into `K` equal segments.
- Sorts each segment independently.
- Merges the sorted segments using `mergeKArrays`.

Compared to standard merge sort:
- Uses `K` partitions instead of 2.
- Reduces recursion depth.
- Merge cost is `O(N log K)`.

---

## Inverse Permutation via Merge Sort

### `inverseMergeK`

Top-level function for computing the inverse permutation using K-way merge sort.

- Calls `mergeKSort` on the full array.
- When `arr1` contains a permutation and `arr2` contains original indices,
  sorting `arr1` constructs the inverse permutation in `arr2`.

---

## Summary and Follow-up

This program demonstrates:

- Random permutation generation
- Two approaches to inverse permutation computation:
  - Naïve `O(N²)`
  - Efficient K-way merge sort with a min-heap
- Synchronization of paired arrays during sorting
- Divide-and-conquer algorithm design
- Explicit dynamic memory management

The implementation is well suited for analyzing performance trade-offs involving recursion depth, heap-based merging, and generalized merge sort strategies. As discussed in the accompanying [report](Assignment.md), `mergeKSort` runs in `O(N log N)` time. The report also presents empirical comparisons of its execution time against the naïve `O(N²)` algorithm, highlighting the practical performance gains of the K-way merge–based approach.
