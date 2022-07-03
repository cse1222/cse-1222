/**
 * @file average.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program computes the average of 3,5,8 and 4.6.13 and 7,9,13,14 and
 * outputs the three averages on seprate lines.
 * @version 0.1
 * @date 2016-09-02
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    /* Prints the average of 3,5,8 */
    cout << "The average of 3, 5, and 8 is: " << (3 + 5 + 8) / 3.0 << endl;
    /* Prints the average of 4,6,13 */
    cout << "The average of 4, 6, and 13 is: " << (4 + 6 + 13) / 3.0 << endl;
    /* Prints the average of 7,9,13,14 */
    cout << "The average of 7, 9, 13, and 14 is: " << (7 + 9 + 13 + 14) / 4.0 << endl;

    return 0;
}
