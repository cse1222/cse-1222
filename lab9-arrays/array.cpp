/**
 * @file array.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program prompts and reads a list of non-negative numbers (ints), i.e. can
 * be 0, into an array, prints the array, finds the maximum value in the array, adds the
 * maximum value to each array number, and then prints the maximum number and the modified
 * array. The input list is terminated by a -99.
 * @version 0.1
 * @date 2016-11-06
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

/* FUNCTION PROTOTYPES */
void read_list(int array[], int &size, const int maxSize);
void print_array(const int array[], const int size);
int find_max(const int array[], const int size);
void array_add(const int x, int array[], const int size);

int main() {
    const int MAX_SIZE = 20;        // max size of array

    int array[MAX_SIZE];            // array of non-negative integers
    int size;                       // number of elements in array

    /* Prompt anf read in list of non-negative integers */
    read_list(array, size, MAX_SIZE);
    cout << endl;

    /* Check that list isn't empty */
    if (size > 0) {
        /* Print original list */
        cout << "Original list (" << size <<  " values):" << endl;
        print_array(array, size);
        cout << endl;

        /* Find and print max value in array */
        int maxValue = find_max(array, size);
        cout << "The maximum value is " << maxValue << endl;
        cout << endl;

        /* Modify list (add max) */
        array_add(maxValue, array, size);

        /* Print modified list */
        cout << "Modified list (" << size <<  " values):" << endl;
        print_array(array, size);
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}

/**
 * @brief Prompts for and reads the list of non-negative inetgers terminated by -99 into an
 * array which stores integer numbers. The number of elements in the input list may be less
 * than the max size. Stop reading whe either the input number is the sentinel value -99 or
 * when the maximum number of elements have been read into the array.
 * 
 * @param array Array of non-negative integers
 * @param size Number of elements in array
 * @param maxSize Max size of array
 */
void read_list(int array[], int &size, const int maxSize) {
    /* Initialize number of elements read into array to 0 */
    size = 0;

    /* Prompt and read in list of non-negative intergera to fill array */
    int value;
    cout << "Enter non-negative numbers (ints) terminated by -99" << endl;
    while (size < maxSize && (cin >> value && value != -99)) {
        /* Check that value entered is non-negative */
        if (value >= 0) {
            array[size++] = value;
        }
    }
}

/**
 * @brief Displays the values that were inserted into the array as a comma separated list
 * and ending with a period.
 * 
 * @param array Array of non-negative integers
 * @param size Number of elements in array
 */
void print_array(const int array[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size-1) {
            cout << ", ";
        } else {
            cout << ".";
        }
    }
    cout << endl;
}

/**
 * @brief Determines the maximum value found in an array of numbers.
 * 
 * @param array Array of non-negative integers
 * @param size Number of elements in array
 * @return The max value in the array. 
 */
int find_max(const int array[], const int size) {
    /* Initialize max value to first array element */
    int maxValue = array[0];

    /* Find max value in array */
    for (int i = 1; i < size; i++) {
        int value = array[i];
        /* Check if value greater than the current max */
        if (value > maxValue) {
            maxValue = value;
        }
    }

    return maxValue;
}

/**
 * @brief Adds a nummber x to every element of an array.
 * 
 * @param x Value to be added to each array element
 * @param array Array of non-negative integers
 * @param size Number of elements in array
 */
void array_add(const int x, int array[], const int size) {
    for (int i = 0; i < size; i++) {
        /* Increment array element */
        array[i] += x;
    }
}
