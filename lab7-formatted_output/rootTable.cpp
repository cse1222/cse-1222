/**
 * @file rootTable.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in the number of roots, a value increment, and a precision
 * and outputs a table of roots x^1/2, x^1/3, ... for the given number of roots and
 * values of x equal to i times the increment up to and including 100.
 * @version 0.1
 * @date 2016-10-19
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int numRoots;       // Number of roots to display (x^2 to x^(n+1))
    int inc;            // Increment value between displayed integers
    int precision;      // Number of significant figures after decimal
    int minWidth(7);    // Minimum column width

    /* Prompt and read in number of roots, value increment, and precision */
    cout << "Enter number of roots: ", cin >> numRoots;
    cout << "Enter value increment (integer): ", cin >> inc;
    cout << "Enter precision: ", cin >> precision;
    cout << endl;

    /* Compute the column width based on the precision */
    int width = 5 + precision;
    if (width < minWidth) {
        width = minWidth;
    }

    /* Print the table header */
    cout << "Value";
    for (int root = 2; root <= numRoots+1; root++) {
        if (root < 10) {
            cout << setw(width-1) << "x^1/" << root;
        } else {
            cout << setw(width-2) << "x^1/" << root;
        }
    }
    cout << endl;

    /* Print the table body */
    for (int x = inc; x <= 100; x += inc) {
        /* Print current value to take roots of */
        cout << setw(5) << x;
        /* Print roots for current value */
        for (int root = 2; root <= numRoots+1; root++) {
            cout.setf(ios::fixed);
            cout.precision(precision);
            cout << setw(width) << pow(x, 1.0/root);
        }
        cout << endl;
    }

    return 0;
}
