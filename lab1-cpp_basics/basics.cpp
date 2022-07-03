/**
 * @file basics.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program illustrates the use of keyboard input, data types, variables,
 * assignment statements, and output.
 * @version 0.1
 * @date 2016-09-01
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    double d;
    int i1, i2;
    char c;

    /* Prompt and read in char, double, and int values */
    cout << "Enter a character: ", cin >> c;
    cout << "Enter a double value: ", cin >> d;
    cout << "Enter value for the first inetegr value: ", cin >> i1;
    cout << "Enter value for the second inetegr value: ", cin >> i2;
    cout << endl;

    /* Print the char, double, and int values entered by user */
    cout << "Your value for the double is " << d << endl;
    cout << "Your value for the first integer is " << i1 << endl;
    cout << "Your value for the second integer is " << i2 << endl;
    cout << "Your character is " << c << endl;
    cout << endl;

    /* Compute and print results of first set of math formulas */
    cout << "The reciprocal of the second integer is " << (1.0 / i2) << endl;
    cout << "The reciprocal of the double is " << (1 / d) << endl;
    cout << "(double)/(second integer) is " << (d / i2) << endl;
    cout << "sum of all three numbers is " << (d + i1 + i2) << endl;
    cout << endl;

    /* Compute and print results of second set of math formulas */
    cout << "The reciprocal of the first integer is " << (1.0 / i1) << endl;
    cout << "(first integer)/(second integer) is " << (i1 / i2) << endl;
    cout << "first integer modulus second integer is " << (i1 % i2) << endl;

    return (0);
}
