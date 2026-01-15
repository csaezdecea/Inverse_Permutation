# Assignment 1  
## Cache Memory and RAM

**Instructor:** Gonzalo Navarro  
**Teaching Assistants:** Diego Salas, Asunción Gómez  

---

## 1. Instructions

The objective of this assignment is to empirically evaluate the cost of **random** and **sequential** memory accesses. To do this, we will evaluate two algorithms for computing the inverse of a permutation of size **N**.

You must implement both algorithms, evaluate them on arrays of size **N**, and finally analyze the results.

The submission consists of a **ZIP file** containing:

1. The source code with the implemented algorithms.
2. A program that executes the algorithms and performs the required tests (including the inputs used, how execution time was measured, etc.).
3. A written report.

The report must include:
- An **introduction**, where you state a hypothesis regarding computational complexity and memory usage.  
  For example: *Algorithm 1 runs in O(N²) time and uses O(log N) memory.*
- A section describing the **development of the two algorithms**.
- A **results section**, where you present and analyze different graphs showing the measured execution times.
- A **conclusions section**, where you confirm (or refute) the previously stated hypothesis.

---

## 2. Algorithms

A permutation  $\pi$ of the set $\{1, N\}$ is a reordering of the values $\{1, 2, \dots, N\}$, where each value appears exactly once.

The inverse of an element is defined as:


$\pi^{-1}(i): \text{the inverse permutation of } i \text{ is } j \text{ such that } \pi(j) = i$.

An example of the inverse of a permutation is shown in Question 2 of **Tutorial 3**.

---

### 2.1 Permutation Algorithm

This algorithm computes the inverse of each element as follows.  
Given a permutation \( \pi \), the inverse is computed using:

$\pi^{-1}(\pi(i)) = i \quad \text{for } i = 1, 2, \dots, N$

---

### 2.2 Merge Sort

The second algorithm consists of implementing the well-known **Merge Sort** algorithm.  
This problem was studied in **Tutorial 3 (Problem 2)**, which can be used as a reference.

The algorithm works as follows:

1. Given the permutation $\pi$, create an array of pairs $(\pi(i), i)$.
2. Sort the array by the first component of the pair using **Merge Sort**.
3. Project only the second component and return this new array.

You are asked to determine the **optimal arity $d$** of Merge Sort.  
Recall that the arity corresponds to the number of blocks into which the array is divided, and this division is applied recursively until subarrays of size 1 are obtained.

To find the optimal arity:
- Generate sufficiently large arrays.
- Test with arities $d = 2, 4, 8, 16, \dots$
- Once the optimal arity is found, test the algorithm on arrays of different sizes (specified in the next section).
- Remember to **plot your results**.

---

## 3. Specifications

- The assignment must be submitted via **U-Cursos**. Late submissions are allowed with a penalty of **1 point per day**.
- The assignment may be completed in groups of up to **3 students**.  
  Each group member must run the tests and specify in the report the computers used, considering their **cache and RAM sizes**.
- Follow **good programming practices**. Well-commented code makes the evaluation easier.
- It is recommended to use **C, C++, or Java** for the implementation and **LaTeX** for the report.
- Use arrays of size  
  $N = 2^{20}, 2^{21}, \dots, 2^{30}$,  
  and repeat the tests **10 times for each N**.
  - Compute the **mean** and **standard deviation** for each $N$.
  - Discuss these values and analyze the **confidence interval** in the report.
- Consider the maximum values supported by data types.  
  For example, the maximum value of a `short int` in C++ is **32767**.  
  If $N > 32767$, a `short` type will not be able to represent all values in the permutation.  
  Take this into account when generating permutations.

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

The implementation is well suited for analyzing performance trade-offs involving recursion depth, heap-based merging, and generalized merge sort strategies. As discussed in the accompanying PDF report, `mergeKSort` runs in `O(N log N)` time. The report also presents empirical comparisons of its execution time against the naïve `O(N²)` algorithm, highlighting the practical performance gains of the K-way merge–based approach.
