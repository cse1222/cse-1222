/**
 * @file hour_glass.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program This program prints an hour glass using the character '#'. The user will
 * enter the number of '#'s on the top row and then the number of rows from the top to the
 * middle row. No row is allowed to have less than two '#'s.
 * @version 0.1
 * @date 2016-10-07
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int sizeTopRow;         // size of the top row of the hour glass
    int numRows;            // number of rows from the top to the middle row

    /* Repeatedly prompt for top row size until valid value is entered */
    cout << "Enter size of the top row: ", cin >> sizeTopRow;
    while (sizeTopRow < 3) {
        cout << "Size of the top row must be at least three." << endl;
        cout << "Enter size of the top row again: ", cin >> sizeTopRow;
    }

    /* Repeatedly prompt for the number of rows until valid value is entered */
    cout << "Enter number of rows: ", cin >> numRows;
    while (numRows < 1 || sizeTopRow - (2 * numRows) < 0) {
        cout << "Invalid number of rows." << endl;
        cout << "Enter number of rows again: ", cin >> numRows;
    }
    cout << endl;

    /* Print the top half of the hour glass */
    for (int row = 0; row < numRows; row++) {
        for (int i = 0; i < row; i++) {
            cout << " ";
        }
        for (int j = 0; j < sizeTopRow - (2 * row); j++) {
            cout << "#";
        }
        cout << endl;
    }
    /* Print the bottom half of the hour glass */
    for (int row = numRows-2; row >= 0; row--) {
        for (int i = 0; i < row; i++) {
            cout << " ";
        }
        for (int j = 0; j < sizeTopRow - (2 * row); j++) {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}
