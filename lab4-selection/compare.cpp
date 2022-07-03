/**
 * @file compare.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in two points and reports if the first point is
 * above/below/left/right or equals the second point.
 * @version 0.1
 * @date 2016-09-22
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    double x1, y1;      // (x,y) coordinates of the first point
    double x2, y2;      // (x,y) coordinates of the second point

    /* Prompt and read in coordinates of first and second points */
    cout << "Enter coordinates of the first point (2 values): ", cin >> x1 >> y1;
    cout << "Enter coordinates of the second point (2 values): ", cin >> x2 >> y2;

    /* Calculate and output location of second point relative to first point */
    if (x2 < x1) {
        if (y2 < y1) {
            cout << "Point (" << x2 << "," << y2 << ") is below and left of point (" << x1 << "," << y1 << ")." << endl;
        } else if (y2 > y1) {
            cout << "Point (" << x2 << "," << y2 << ") is above and left of point (" << x1 << "," << y1 << ")." << endl;
        } else {
            cout << "Point (" << x2 << "," << y2 << ") is left of point (" << x1 << "," << y1 << ")." << endl;
        }
    } else if (x2 > x1) {
        if (y2 < y1) {
            cout << "Point (" << x2 << "," << y2 << ") is below and right of point (" << x1 << "," << y1 << ")." << endl;
        } else if (y2 > y1) {
            cout << "Point (" << x2 << "," << y2 << ") is above and right of point (" << x1 << "," << y1 << ")." << endl;
        } else {
            cout << "Point (" << x2 << "," << y2 << ") is right of point (" << x1 << "," << y1 << ")." << endl;
        }
    } else {
        if (y2 < y1) {
            cout << "Point (" << x2 << "," << y2 << ") is below point (" << x1 << "," << y1 << ")." << endl;
        } else if (y2 > y1) {
            cout << "Point (" << x2 << "," << y2 << ") is above point (" << x1 << "," << y1 << ")." << endl;
        } else {
            cout << "Point (" << x2 << "," << y2 << ") equals point (" << x1 << "," << y1 << ")." << endl;
        }
    }

    return (0);
}
