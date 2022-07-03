/**
 * @file pyramid.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads a positive odd whole number n and prints a pyramid where teh last
 * row contains all numbers from n down to 1 (descending order), the second to last row displays
 * all numbers from n-1 down to 2, the third to last row displays all numbers from n-2 down to 3,
 * etc. The first row will contain only a single value, i.e. the middle value in the range, i.e.
 * n down to 1. Each successive row contains two more values than the previous row. The i'th row
 * contains 2i-1 values. Each column displays the same number. If a row has more than 10 digits,
 * the digit after 0 should start again from 9.
 * @version 0.1
 * @date 2016-10-10
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int n;              // Number of integers in last row
    double midPoint;    // Value of alternating harmonic series from k=1 to k=n

    /* Promts, reads in, and validate 'n' */
    cout << "Enter a positive odd number: ", cin >> n;
    while (n < 0 || n % 2 == 0) {
        cout << "Enter a positive odd number. Try again: ", cin >> n;
    }
    cout << endl;

    /* Compute the midpoint of the pyramid */
    midPoint = (n / 2) + (n % 2);

    /* Print the pyramid */
    for (int row = 0; row < midPoint; row++) {
        /* Print the indent for the current row */
        for (int indent = midPoint; indent > row+1; indent--) {
            cout << " ";
        }
        /* Print the digits for the current row */
        for (int digit = midPoint + row; digit >= midPoint - row; digit--) {
            cout << digit % 10;
        }
        cout << endl;
    }

    return 0;
}
