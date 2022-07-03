/**
 * @file polarcoord.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in the polar coordinates of a point and
 * computes and outputs the cartesian coordinates.
 * @version 0.1
 * @date 2016-10-28
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

/* Function prototypes */
double degrees2radians(double angle);
void compute_coord(double radius, double angle, double &x, double &y);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main() {
    double angle_degrees(0.0), angle_radians(0.0), radius(0.0);
    double coord_x(0.0), coord_y(0.0);

    // Read polar coordinates
    cout << "Enter radius: ";
    cin >> radius;

    cout << "Enter polar angle (degrees): ";
    cin >> angle_degrees;

    // Convert degrees to radians
    angle_radians = degrees2radians(angle_degrees);

    // Compute Cartesian (x,y) coordinates
    compute_coord(radius, angle_radians, coord_x, coord_y);

    // Output Cartesian coordinates
    cout << "Cartesian coordinates: ";
    cout << "(" << coord_x << "," << coord_y << ")" << endl;

    return 0;
}

/**
 * @brief Takes a given angle in degrees and converts it to its equivalent
 * angle in radians.
 * 
 * @param angle The angle in degrees.
 * @return The given angle in radians. 
 */
double degrees2radians(double angle) {
    double radians = angle * (M_PI / 180);
    return radians;
}

/**
 * @brief Computes the Cartesian (x,y) coordinates of a point from its polar
 * coordinates (radius,angle), where angle is measured in radians.
 * 
 * @param radius The polar radius of the point.
 * @param angle The polar angle (in radians) of the point.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 */
void compute_coord(double radius, double angle, double &x, double &y) {
    x = radius * cos(angle);
    y = radius * sin(angle);
}
