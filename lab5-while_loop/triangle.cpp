/**
 * @file triangle.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief Reads in the number of rows and prints n rows of digits where the
 * i'th row is 1234 ... k. If k is 10 or more digits, then the digit after
 * 9 should start again from 0.
 * @version 0.1
 * @date 2016-10-03
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int n;          // number of rows
    int row(1);     // current row number (counter variable)
    int k(1);       // current digit in row (counter variable)

    /* Prompt and read in value for number of rows */
    cout << "Enter number of rows: ", cin >> n;

    /* Print the triangle */
    row = n;
    while (row > 0) {
        k = 1;
        while (k <= row) {
            cout << (k % 10);
            k++;
        }
        cout << endl;
        row--;
    }

    return 0;
}
