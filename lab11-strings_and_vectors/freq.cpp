/**
 * @file freq.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program reads text from the user and then computes the frequency of each vowel
 * as well as the number of consonants that appear in the text. A vowel is one of the letters
 * a, e, i, o, u, or y. Note that y can be considered to be a vowel or a consonant. We will
 * count a lower case or capitalized version of a letter the same. The frequency of a letter
 * in some text is the number of times it appears in that text, i.e. its count. Note that
 * non-alphabetic characters are ignored and so not counted.
 * @version 0.1
 * @date 2016-11-20
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/* FUNCTION PROTOTYPES */
void init_vectors(vector<char> &vowels, vector<int> &frequencies);
string read_text(const string &prompt);
bool is_alphabetic(const char character);
void create_list(const string &str_text, vector<char> &vec_text);
bool is_member(const vector<char> &list, char character);
int find_index(const vector<char> &list, char character);
int compute_vowel_freqs(const vector<char> &text, const vector<char> &vowels, vector<int> &freqs);
void display_characters(const vector<char> &characters, const int colwidth);
void display_freqs(const vector<int> &freqs, const int colwidth);

int main() {
    const int       COLUMNWIDTH = 2;    // width of fields for displaying formatted results
    
    vector<char>    vowels;             // vector holding the six vowels in lower case
    vector<int>     freqs;              // vector holding the counts  of each vowel eencountered in the text
    string          input;              // holds the original input text typed by the user
    vector<char>    text;               // vector holding the alphabetic characters only of the input text
    int             numConsonants = 0;  // number of consonant characters found in the input text

    /* Initialize the list of vowels and vowel frequencies */
    init_vectors(vowels, freqs);

    /* Prompt and read input text from user */
    input = read_text("Enter your text: ");

    /* Copy the characters (ignoring non-alphabetic characters) in the input to the vector of characters */
    create_list(input, text);

    /* Compute the frequencies of vowels and consonants from the input text */
    numConsonants = compute_vowel_freqs(text, vowels, freqs);

    /* Print the vowels, their frequencies, and the number of consonants */
    display_characters(vowels, COLUMNWIDTH);
    display_freqs(freqs, COLUMNWIDTH);
    cout << "There are " << numConsonants << " consonants." << endl;

    return 0;
}

/**
 * @brief Initialize vectors of vowels and their frequencies.
 * 
 * @param vowels The vector holding the six vowels in lower case
 * @param frequencies The vector holding the count of each vowel encountered
 */
void init_vectors(vector<char> &vowels, vector<int> &frequencies) {
    /* Get array of vowels to initialize vector */
    const int   SIZE            = 6;
    int         letters[SIZE]   = {'a', 'e', 'i', 'o', 'u', 'y'};

    /* Initialize vectors of vowels and their starting frequencies */
    for (int i = 0; i < SIZE; i++) {
        vowels.push_back(letters[i]);
        frequencies.push_back(0);
    }
}

/**
 * @brief Prompt and read some text from the user.
 * 
 * @param prompt Prompt displayed to user
 * @return The entered text as a string. 
 */
string read_text(const string &prompt) {
    string input;
    
    /* Prompt and read line of text from the user */
    cout << prompt;
    getline(cin, input);

    return input;
}

/**
 * @brief Determines if a character is an alphabetic character (a-z or A-Z).
 * 
 * @param character The specific character to test
 * @return True if the character is alphabetic.
 * @return False otherwise. 
 */
bool is_alphabetic(const char character) {
    /* Define the ASCII ranges for alphabetic characters */
    const int   LOWER_MIN = (int)'a', LOWER_MAX = (int)'z';
    const int   UPPER_MIN = (int)'A', UPPER_MAX = (int)'Z';

    /* Check if character is alphabetic (lower case) */
    if (LOWER_MIN <= character && character <= LOWER_MAX) {
        return true;
    }

    /* Check if character is alphabetic (upper case) */
    if (UPPER_MIN <= character && character <= UPPER_MAX) {
        return true;
    }

    /* Character is not alphabetic */
    return false;
}

/**
 * @brief Copies only the alphabetic characters from the input text to a vector.
 * 
 * @param str_text The string holding the original input text
 * @param vec_text The vector holding only the alphabetic characters of the input text
 */
void create_list(const string &str_text, vector<char> &vec_text) {
    for (int i = 0; i < str_text.length(); i++) {
        char character = str_text[i];
        /* Check if current character is alphabetic, if so add to vector */
        if (is_alphabetic(character)) {
            vec_text.push_back(character);
        }
    }
}

/**
 * @brief Checks if a character appears in a given vector of characters.
 * 
 * @param list The vector holding the list of characters
 * @param character The specific character to look for
 * @return True if the given vector contains the character, false otherwise.
 */
bool is_member(const vector<char> &list, char character) {
    for (int i = 0; i < list.size(); i++) {
        /* Check if given character matches current character in the list */
        if (character == list[i]){
            return true;    
        }
    }
    /* Character not found in the list */
    return false;
}

/**
 * @brief Finds the index of the first occurence of a character in a given vector of
 * characters.
 * 
 * @param list The vector holding the list of characters
 * @param character The specific character to look for
 * @return The the index of the first occurence of the character in the vector, or
 * the value -1 if the character was not found in the vector.
 */
int find_index(const vector<char> &list, char character) {
    for (int i = 0; i < list.size(); i++) {
        /* Check if given character matches current character in the list */
        if (character == list[i]){
            return i;    
        }
    }
    /* Character not found in the list */
    return -1;
}

/**
 * @brief Computes the frequency of each of the six vowels and the number of
 * consonants found in the input text.
 * 
 * @param text The vector holding only the alphabetic characters of the input text
 * @param vowels The vector holding the six vowels in lower case
 * @param freqs The vector holding the count of each vowel encountered
 * @return The number of consonants found in the text.
 */
int compute_vowel_freqs(const vector<char> &text, const vector<char> &vowels, vector<int> &freqs) {
    int numConsonants = 0;
    for (int i = 0; i < text.size(); i++) {
        /* Get the lower case version of the current character */
        char character = tolower(text[i]);

        /* Check if the character is a vowel or consonant */
        if (is_member(vowels, character)) {
            /* Increment frequency of corresponding vowel */
            freqs[find_index(vowels, character)]++;
        } else {
            /* Increment consonant frequency */
            numConsonants++;
        }
    }
    return numConsonants;
}

/**
 * @brief Prints the characters from a vector of characters on a single line.
 * 
 * @param characters The vector holding the list of characters
 * @param colwidth Width of fields for displaying formatted results
 */
void display_characters(const vector<char> &characters, const int colwidth) {
    for (int i = 0; i < characters.size(); i++) {
        /* Print (formatted) the current character */
        cout << setw(colwidth) << characters[i];
        if (i < characters.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
}

/**
 * @brief Prints the counts from a vector of integers on a single line.
 * 
 * @param freqs The vector holding the count of each vowel encountered
 * @param colwidth Width of fields for displaying formatted results
 */
void display_freqs(const vector<int> &freqs, const int colwidth) {
    for (int i = 0; i < freqs.size(); i++) {
        /* Print (formatted) the current count */
        cout << setw(colwidth) << freqs[i];
        if (i < freqs.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
}
