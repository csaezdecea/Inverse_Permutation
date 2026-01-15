#include "InversePerm.hpp"
#include <memory>
#include <chrono>
#include <iostream>
#include <cstdlib>   // std::atoi
#include <cmath>     // std::pow


using namespace std;
using namespace std::chrono;

// Driver's code
int main(int argc, char* argv[])
{
    // Check arguments
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <power> <k>" << endl;
        return EXIT_FAILURE;
    }

    // Read parameters
    int power = std::atoi(argv[1]);
    int k     = std::atoi(argv[2]);

    if (power <= 0 || k <= 0) {
        cerr << "Error: power and k must be positive integers." << endl;
        return EXIT_FAILURE;
    }

    int npr = 16;
    int n = static_cast<int>(pow(2, power));

    int* piarr;
    int* iarr;
    int* piaux;

    // Dynamically allocate memory
    piarr = (int*)malloc(n * sizeof(int));
    iarr  = (int*)malloc(n * sizeof(int));

    int ncheck = (n < 1600 * 10) ? min(1600, n) : n / 10;
    piaux = (int*)malloc(ncheck * sizeof(int));

    if (!piarr || !iarr || !piaux) {
        cerr << "Memory allocation failed." << endl;
        return EXIT_FAILURE;
    }

    cout << "######### RESULTS ########" << endl;
    cout << "log2(N) = " << power << "  k = " << k << endl;
    cout << "Size of integers in bytes = " << sizeof(int) << endl;
    cout << "Size of an array in MB = " << round(n * sizeof(int) / 1E6) << endl;

    if (n < 16) npr = n;

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        piarr[i] = i + 1;
        iarr[i]  = i + 1;
    }

    // Generate permutation
    permutation(piarr, n);

    for (int i = 0; i < ncheck; i++)
        piaux[i] = piarr[i];

    //cout << "Arrays before sorting: " << endl;
    //cout << "INT_MAX = " << INT_MAX << " " << pow(2, 28) << endl;

    //printArray(piarr, npr);
    //printArray(iarr, npr);

    auto start = high_resolution_clock::now();

    inverseMergeK(piarr, iarr, n, k);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    printf("mergeKsort ex time = %.2f s \n", duration.count()/1000.);

    //cout << "mergeKsort execution time = "
     //    << duration.count() << " ms" << endl;

    //cout << "Arrays after sorting: " << endl;
    //printArray(piarr, npr);
    //printArray(iarr, npr);

    // Verification
    bool checkbool = true;
    for (int i = 0; i < ncheck; i++) {
        checkbool = checkbool && (iarr[piaux[i] - 1] == (i + 1));
    }

    if (checkbool) {
        cout << "The inverse of the permutation is correct until n = "
             << ncheck << endl;
    } else {
        cout << "Error: inverse permutation check failed." << endl;
    }

    // Free memory
    free(piarr);
    free(iarr);
    free(piaux);

    return EXIT_SUCCESS;
}
