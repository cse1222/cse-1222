/**
 * @file fallVenus.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in the time (t), in seconds, and calculates the velocity,
 * in meters per second, and the falling distance, in meters, for the given time. The
 * program then outputs these values to the user.
 * @version 0.1
 * @date 2016-09-09
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    double g = 8.73;        // Acceleration due to gravity in m/s^2
    double t;               // Time in seconds
    double velocity;        // Velocity on Venus in m/s
    double distance;        // Falling distance on Venus in m/s^2

    //* Prompt and read in the elapsed time */
    cout << "Enter the time: ", cin >> t;

    /* Compute projectile velocity and distance traveled */
    velocity = g * t;
    distance = 0.5 * velocity * t;

    /* Print projectile velocity and distance traveled */
    cout << "After " << t << " seconds, the velocity on venus is " << velocity << " meters per second." << endl;
    cout << "After " << t << " seconds, the falling distance on venus is " << distance << " meters." << endl;

    return (0);
}
