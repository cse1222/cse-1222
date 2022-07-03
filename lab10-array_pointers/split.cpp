/**
 * @file split.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads a list of numbers into an array, splits the list into a list of
 * negative numbers and a list of non-negative numbers, each in their separate arrays, and
 * then outputs the arrays of negative and non-negative numbers. A negative integer is one
 * that is strictly less than 0. All other integers are non-negative integers.
 * @version 0.1
 * @date 2016-11-12
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/* FUNCTION PROTOTYPES */
void count(const int array[], const int size, int &numNeg, int &numNonNeg);
void split(const int list[], const int size, int listNeg[], const int sizeNeg, int listNonNeg[], const int sizeNonNeg);
void print_array(const int array[], const int size);

int main() {
    /* Prompt and read in number of list elements */
    int n;
    cout << "Enter number of elements: ", cin >> n;

    /* Prompt and read elements into list */
    cout << "Enter list:" << endl;
    int *list = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    /* Get number of negative integers and list of non-negative integers in list */
    int n_neg, n_nonNeg;
    count(list, n, n_neg, n_nonNeg);

    /* Split original list into list of negative integers and list of non-negative integers */
    int *listNeg = new int[n_neg];
    int *listNonNeg = new int[n_nonNeg];
    split(list, n, listNeg, n_neg, listNonNeg, n_nonNeg);

    /* Print list of negative elements and list of non-negative elements */
    cout << "Negative elements:" << endl;
    print_array(listNeg, n_neg);
    cout << "Non-negative elements:" << endl;
    print_array(listNonNeg, n_nonNeg);

    /* Free dynamically allocated memory */
    delete[] list;
    delete[] listNeg;
    delete[] listNonNeg;

    return 0;
}

/**
 * @brief Counts the number of negative elements and the number of non-negative elements of
 * an array.
 * 
 * @param array The array of integers
 * @param size The number of elements in the array
 * @param numNeg The number of negative elements in the array
 * @param numNonNeg The number of non-negative elements in teh array
 */
void count(const int array[], const int size, int &numNeg, int &numNonNeg) {
    /* Initialize counts to 0 */
    numNeg      = 0;
    numNonNeg   = 0;

    /* Count number of negative vs non-negative elements */
    for (int i = 0; i < size; i++) {
        /* Checks whether element is negative or non-negative */
        if (array[i] < 0) {
            numNeg++;
        } else {
            numNonNeg++;
        }
    }
}

/**
 * @brief Takes, as input, 3 arrays, A, B, and C, and stores the negative elements of A in B
 * and the non-negative elements of A in C. The size of array B should be exactly the number
 * of negative elements in array A. The size of array C should be exactly the number of
 * non-negative elements in array A. Checks that teh number copied equals exactly the array
 * size. If it does not, prints an error message and exits.
 * 
 * @param list The list of integers
 * @param size The number of elements in the list
 * @param listNeg The list of negative integers
 * @param sizeNeg The number of elements in the negative list
 * @param listNonNeg The list of non-negative integers
 * @param sizeNonNeg The number of elements in the non-negative list
 */
void split(const int list[], const int size, int listNeg[], const int sizeNeg, int listNonNeg[], const int sizeNonNeg) {
    int numNeg      = 0;    // number of negative elements copied
    int numNonNeg   = 0;    // number of non-negative elements copied

    /* Split original list into negative and non-negative elements */
    for (int i = 0; i < size; i++) {
        int value = list[i];
        /* Checks whether element is negative or non-negative */
        if (value < 0) {
            /* Element is negative, so add to negative list */
            listNeg[numNeg++] = value;
        } else {
            /* Element is non-negative, so add to non-negative list */
            listNonNeg[numNonNeg++] = value;
        }
    }

    /* Check for copy error and print appropriate error message and exit */
    if (numNeg != sizeNeg) {
        cout << "ERROR: Size of negative list does not equal number of negative integers copied" << endl;
        exit(0);
    }
    if (numNonNeg != sizeNonNeg) {
        cout << "ERROR: Size of non-negative list does not equal number of non-negative integers copied" << endl;
        exit(0);
    }
}

/**
 * @brief Prints the elements of an array.
 * 
 * @param array The array of integers
 * @param size The number of elements in the array
 */
void print_array(const int array[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    cout << endl;
}
