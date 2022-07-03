/**
 * @file vector2D.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in a pair of 2D vectors and a scalar value and then
 * applies the following vector operations: addition, subtraction, scalar
 * multiplication, and perpendicularity.
 * @version 0.1
 * @date 2016-10-24
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const double EPSILON(1e-12);        // equality determining value

/* FUNCTION PROTOTYPES */
void read_vector(const string &prompt, double &x, double &y);
double vector_length(double x, double y);
void write_vector(const string &message, double x, double y);
void vector_add(double x1, double y1, double x2, double y2, double &x3, double &y3);
void vector_subtract(double x1, double y1, double x2, double y2, double &x3, double &y3);
void scalar_mult(double x1, double y1, double s, double &x2, double &y2);
void normalize(double &x, double &y);
void perpendicular(double x1, double y1, double x2, double y2);

// *** DO NOT CHANGE ANY CODE IN THE MAIN FUNCTION
int main() {
    double u1, v1;          // coordinates of first vector
    double u2, v2;          // coordinates of second vector
    double u3, v3;
    double scalar;

    /* Prompt and read in 2D vectors */
    read_vector("Enter first vector (2 floats): ", u1, v1);
    read_vector("Enter second vector (2 floats): ", u2, v2);

    /* Prompt and read in scalar multiplier */
    cout << "Enter scalar multiplier: ", cin >> scalar;
    cout << endl;

    /* Print 2D vectors */
    write_vector("First vector: ", u1, v1);
    write_vector("Second vector: ", u2, v2);
    cout << endl;

    /* Compute addition of vectors (v1 + v2) and print result */
    vector_add(u1, v1, u2, v2, u3, v3);
    write_vector("Vector add: ", u3, v3);

    /* Compute subtraction of vectors (v1 - v2) and print result */
    vector_subtract(u1, v1, u2, v2, u3, v3);
    write_vector("Vector subtract: ", u3, v3);

    /* Compute scalar multiplication of first vector (s * v1) and print result */
    scalar_mult(u1, v1, scalar, u3, v3);
    write_vector("Scalar multiplier: ", u3, v3);
    cout << endl;

    /* Determine and print the perpendicularity of the two vectors */
    write_vector("First vector: ", u1, v1);
    write_vector("Second vector: ", u2, v2);
    perpendicular(u1, v1, u2, v2);

    return 0;
}

/**
 * @brief Pronpts and reads in the (x,y) coordinates of a 2D vector.
 * 
 * @param prompt Prompt displayed to user
 * @param x The x-coordinate of a 2D vector
 * @param y The y-coordinate of a 2D vector
 */
void read_vector(const string &prompt, double &x, double &y) {
    cout << prompt, cin >> x >> y;
}

/**
 * @brief Calculates the length of a 2D vector.
 * 
 * @param x The x-coordinate of a 2D vector
 * @param y The y-coordinate of a 2D vector
 * @return The length of the vector. 
 */
double vector_length(double x, double y) {
    return (sqrt(pow(x, 2) + pow(y, 2)));
}

/**
 * @brief Prints the components and length of a 2D vector.
 * 
 * @param message Message to be displayed before coordinates of vector
 * @param x The x-coordinate of a 2D vector
 * @param y The y-coordinate of a 2D vector
 */
void write_vector(const string &message, double x, double y) {
    cout << message << "(" << x << ", " << y << ") has length " << vector_length(x, y) << endl; 
}

/**
 * @brief Adds two 2D vectors and results in a new 2D vector.
 * 
 * @param x1 The x-coordinate of the first 2D vector to add
 * @param y1 The y-coordinate of the first 2D vector to add
 * @param x2 The x-coordinate of the second 2D vector to add
 * @param y2 The y-coordinate of the second 2D vector to add
 * @param x3 The x-coordinate of the resultant 2D vector
 * @param y3 The y-coordinate of the resultant 2D vector
 */
void vector_add(double x1, double y1, double x2, double y2, double &x3, double &y3) {
    x3 = x1 + x2;
    y3 = y1 + y2;
}

/**
 * @brief Subtracts two 2D vectors and results in a new 2D vector.
 * 
 * @param x1 The x-coordinate of the first 2D vector to subtract
 * @param y1 The y-coordinate of the first 2D vector to subtract
 * @param x2 The x-coordinate of the second 2D vector to subtract
 * @param y2 The y-coordinate of the second 2D vector to subtract
 * @param x3 The x-coordinate of the resultant 2D vector
 * @param y3 The y-coordinate of the resultant 2D vector
 */
void vector_subtract(double x1, double y1, double x2, double y2, double &x3, double &y3) {
    x3 = x1 - x2;
    y3 = y1 - y2;
}

/**
 * @brief Applies scalar multiplication to a 2D vector and results in a new 2D vector.
 * 
 * @param x1 The x-coordinate of the 2D vector to multiply
 * @param y1 The y-coordinate of the 2D vector to multiply
 * @param s The scalar multiplier by which to multiply the vector
 * @param x2 The x-coordinate of the resultant 2D vector
 * @param y2 The y-coordinate of the resultant 2D vector
 */
void scalar_mult(double x1, double y1, double s, double &x2, double &y2) {
    x2 = s * x1;
    y2 = s * y1;
}

/**
 * @brief Normalizes 2D vetcor (x,y) by dividing by its length. Normalization results in a new
 * vector that has the same direction but has a length of 1, called a unit vector.
 * 
 * @param x The x-coordinate of  a 2D vector
 * @param y The y-coordinate of  a 2D vector
 */
void normalize(double &x, double &y) {
    /* Determine vector length */
    double length = vector_length(x, y);

    /* Check that length is non-zero to avoid division error */
    if (abs(length - 0) < EPSILON) {
        x = 0;
        y = 0;
    } else {
        /* Normalize vector components */
        x /= length;
        y /= length;
    }
}

/**
 * @brief Determines whether two 2D vectors are perpendicular to each other.
 * 
 * @param x1 The x-coordinate of the first 2D vector to test for perpendicularity
 * @param y1 The y-coordinate of the first 2D vector to test for perpendicularity
 * @param x2 The x-coordinate of the second 2D vector to test for perpendicularity
 * @param y2 The y-coordinate of the second 2D vector to test for perpendicularity
 */
void perpendicular(double x1, double y1, double x2, double y2) {
    /* Normalize the two vectors */
    normalize(x1, y1);
    normalize(x2, y2);

    /* Compute two perpendicular vectors p1 and p2 to v1 */
    double px1 = -y1, py1 = x1;
    double px2 = -px1, py2 = -py1;

    /* Check whether v2 is the same as either p1 or p2, if so the vectors are perpendicular */
    if (abs(x2 - px1) < EPSILON && abs(y2 - py1) < EPSILON) {
        cout << "Vectors are PERPENDICULAR." << endl;
    } else if (abs(x2 - px2) < EPSILON && abs(y2 - py2) < EPSILON) {
        cout << "Vectors are PERPENDICULAR." << endl;
    } else {
        cout << "Vectors are NOT PERPENDICULAR." << endl;
    }
}
