/**
 * @file alt_harmonic.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads a whole number ≥ 1 and computes the alternating harmonic series:
 * sum from k=1 to k=n of ((-1)^k+1)/k.
 * @version 0.1
 * @date 2016-10-07
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int     n;          // Number of terms to look at in sereies
    double  sum(0);     // Value of alternating harmonic series from k=1 to k=n

    /* Promts, reads in, and validates n (the number of terms) */
    cout << "Enter n: ", cin >> n;
    while (n < 1) {
        cout << "Value n must be 1 or greater. Try again: ", cin >> n;
    }

    /* Compute the alternating harmonic series */
    for (int k = 1; k <= n; k++) {
        sum += pow(-1, k+1) / k;
    }

    /* Print the resulting sum */
    cout << "The alternating series converges to " << sum << endl;

    return 0;
}
