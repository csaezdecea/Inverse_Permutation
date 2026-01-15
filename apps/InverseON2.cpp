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
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <power>" << endl;
        return EXIT_FAILURE;
    }

    // Read parameters
    int power = std::atoi(argv[1]);

    if (power <= 0) {
        cerr << "Error: power must be a positive integer." << endl;
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
    cout << "log2(N) = " << power << endl;
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


    auto start = high_resolution_clock::now();

    inversePON2(piarr, iarr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    printf("ON2 ex time = %.2f s \n", duration.count()/1000.);

    
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
