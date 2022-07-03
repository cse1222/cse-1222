/**
 * @file isprime.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in a minimum and maximum integer and
 * returns all prime numbers between the minimum and maximum.
 * @version 0.1
 * @date 2016-11-01
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

/* Function prototypes */
void read_range(int &rangeMin, int &rangeMax);
bool is_prime(int num);

// DO NOT MODIFY THE MAIN ROUTINE IN ANY WAY
int main() {
    int imin(0), imax(0);

    // Read in range
    read_range(imin, imax);

    // Print prime numbers
    cout << "Primes:";
    for (int j = imin; j <= imax; j++) {
        if (is_prime(j)) {
            cout << " " << j;
        }
    }
    cout << endl;

    return 0;
}

/**
 * @brief Prompts for the minimum and maximum values. If the minimum or maximum
 * values are less than 2, then the program prints an error message and prompts
 * again for the two values. If the minimum value is greater than the maximum
 * value, then the program prints an error message and prompts again for the
 * two values.
 * 
 * @param rangeMin The minimum value of the range.
 * @param rangeMax The maximum value of the range.
 */
void read_range(int &rangeMin, int &rangeMax) {
    /* Promp for range input from user */
    cout << "Enter minimum and maximum: ", cin >> rangeMin >> rangeMax;
    /* Validate the range */
    while ((rangeMin < 2 || rangeMax < 2) || rangeMin > rangeMax) {
        /* Print appropriate error message */
        if (rangeMin < 2 || rangeMax < 2) {
            cout << "ERROR: Minimum and maximum must be at least 2." << endl;
        }
        if (rangeMin > rangeMax) {
            cout << "ERROR: Minimum must be less than or equal to maximum." << endl;
        }
        /* Reprompt for input */
        cout << "Enter minimum and maximum: ", cin >> rangeMin >> rangeMax;
    }
}

/**
 * @brief Determines if a number is prime or not.
 * 
 * @param num The value to be tested for primality.
 * @return True if the input parameter is prime and false otherwise.
 * @return true 
 * @return false 
 */
bool is_prime(int num) {
    /* Check if divisible by any number in range [2, num-1] */
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
