/**
 * @file cos.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in an angle x in radians and computes cos(x) and
 * cos(x) + cos(x)*cos(x) and the square root of (1+cos(x)).
 * @version 0.1
 * @date 2016-09-02
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;

    /* Read in angle in radians */
    cout << "Enter angle (radians): ", cin >> x;

    /* Compute cos(x) */
    y = cos(x);

    /* Prints formula solutions */
    cout << "cos(x) = " << y << endl;
    cout << "cos(x) + cos(x)*cos(x) = " << y + y*y << endl;
    cout << "The square root of (1+cos(x)) = " << sqrt(1+y) << endl;

    return 0;
}
