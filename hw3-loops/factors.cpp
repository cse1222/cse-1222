/**
 * @file factors.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program prompts for an integer greater than one that represents the low
 * end of a range and a second integer greater than or equal to the first integer that
 * represents the high end of a range. The program will print the factors of integers
 * in this range in descending order.
 * @version 0.1
 * @date 2016-10-03
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int rangeMin, rangeMax;

    /* Repeatedly promt for min integer until valid value is entered */
    cout << "Enter min integer: ", cin >> rangeMin;
    while (rangeMin < 2) {
        cout << "Number must be greater than 1." << endl;
        cout << "Enter min integer again: ", cin >> rangeMin;
    }

    /* Repeatedly promt for max integer until valid value is entered */
    cout << "Enter max integer: ", cin >> rangeMax;
    while (rangeMax < rangeMin) {
        cout << "Number must be greater than or equal to " << rangeMin << "." << endl;
        cout << "Enter max integer again: ", cin >> rangeMax;
    }
    cout << endl;

    /* Print factors of all numbers in range */
    cout << "Factors of all numbers in the range: [ " << rangeMin << ", " << rangeMax << " ]" << endl;
    for (int y = rangeMax; y >= rangeMin; y--) {
        /* Integer 1 is a trivial factor of all numbers */
        cout << y << ": " << 1;
        /* Print factors of current number */
        for (int x = 2; x <= y; x++) {
            /* Check if value is a factor of the current number */
            if (y % x == 0) {
                cout << ", " << x;
            }
        }
        cout << endl;
    }

    return 0;
}
