/**
 * @file projectileDist.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program will read in the initial velocity (v), in meters per second, from
 * the user and calculates the horizontal distance travelled, in meters, by a projectile
 * shot at a 45 degree angle with an initial velocity v on earth. The program will then
 * output this value to the user.
 * @version 0.1
 * @date 2016-09-09
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    double g = 9.81;        // Acceleration due to gravity in m/s^2
    double v;               // Initial velocity in m/s
    double distance;        // Horizontal distance traveled in meters

    /* Prompt and read in initial projectile velocity */
    cout << "Enter the initial velocity (meter/second): ", cin >> v;

    /* Compute horizontal distance traveled by projectile */
    distance = (v * v) / g;

    /* Print horizontal distance traveled by projectile */
    cout << "Horizontal distance travelled is " << distance << " meters." << endl;

    return (0);
}
