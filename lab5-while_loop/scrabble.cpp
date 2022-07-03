/**
 * @file srabble.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads in text one character at at time and counts the number of
 * occurances of the following letters: 'a', 'g', 'm', 'f', 'k', and 'j' in the text,
 * and determines a total score for the text using a point based scheme. Both lower
 * case and upper case letters are counted together. When a period, '.', or exclamation
 * mark, '!', appears in the input text, the program prints how many of each letter
 * above only, the total score of the text, anf halts. Each letter being counted is
 * assigned a score as follows: 'a' (1 point), 'g' (2 points), 'm' (3 points), 'f'
 * (4 points), 'k' (5 points), and 'j' (8 points). All other characters have a score of
 * 0 points. The total score of the input text is calculated by summing the number of
 * occurences of a letter above multiplied by its score.
 * @version 0.1
 * @date 2016-10-03
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
using namespace std;

int main() {
    char    input;          // Individual character input
    int     totalScore;     // Total score based on points system
    int     count_a(0);     // Keeps track of number of a's
    int     count_g(0);     // Keeps track of number of g's
    int     count_m(0);     // Keeps track of number of m's
    int     count_f(0);     // Keeps track of number of f's
    int     count_k(0);     // Keeps track of number of k's
    int     count_j(0);     // Keeps track of number of j's

    /* Prompt for text from user */
    cout << "Enter text:" << endl;
    
    /* Read and count characters */
    while (cin >> input && !(input == '.' || input == '!')) {
        switch (input) {
            case 'a':
            case 'A':
                count_a++;
                break;
            case 'g':
            case 'G':
                count_g++;
                break;           
            case 'm':
            case 'M':
                count_m++;
                break;   
            case 'f':
            case 'F':
                count_f++;
                break;   
            case 'k':
            case 'K':
                count_k++;
                break;   
            case 'j':
            case 'J':
                count_j++;
                break;   
            default:
                break;
        }
    }
    cout << endl;

    /* Print count of each 'selected' character */
    cout << "Number of a's (worth 1 point each) : " << count_a << endl;
    cout << "Number of g's (worth 2 point each) : " << count_g << endl;
    cout << "Number of m's (worth 3 point each) : " << count_m << endl;
    cout << "Number of f's (worth 4 point each) : " << count_f << endl;
    cout << "Number of k's (worth 5 point each) : " << count_k << endl;
    cout << "Number of j's (worth 8 point each) : " << count_j << endl;
    cout << endl;

    /* Calculate and print total score */
    totalScore = (1*count_a) + (2*count_g) + (3*count_m) + (4*count_f) + (5*count_k) + (8*count_j);
    cout << "Total score: " << totalScore << endl;

    return 0;
}
