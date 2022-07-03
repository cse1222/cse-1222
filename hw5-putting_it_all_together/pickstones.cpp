/**
 * @file pickstones.cpp
 * @author Conner Graham (connergraham888@gmail.com)
 * @brief This program plays a variation of the Chinese game "Tsyan-shizi" called the game
 * of NIM. This version of the game starts with up to 20 rods and up to 10 stones in rod.
 * Two players take turns removing stones from the rods. On a player's turn, he/she chooses
 * a rod and removes one or more stones from that rod. He/she can remove all stones from
 * the rod. The player who takes the last stone from the rods (so that all rods are empty)
 * wins.
 * @version 0.1
 * @date 2016-11-06
 * 
 * @copyright Copyright (c) 2016
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* FUNCTION PROTOTYPES */
int read_num_rods(const int maxRods);
void read_rods(int rods[], const int numRods, const int maxStones);
    void read_num_stones(int &stones, const int index, const int maxStones);
void print_rods(const int rods[], const int numRods);
    void print_row(const int index, const int rodStones, const int totalStones);
        string rod_representation(const int rodStones);
        double stones_fraction(const int rodStones, const int totalStones);
void print_stats(const int rods[], const int numRods);
    void print_min_stones(const int rods[], const int numRods);
    void print_max_stones(const int rods[], const int numRods);
    void print_avg_stones(const int rods[], const int numRods);
bool game_over(const int rods[], const int numRods);
void read_player_move(const int rods[], const int numRods, const int id, int &rodIndex, int &stonesRemoved);
    int choose_rod(const int id);
    void validate_rod_index(const int id, int &rodIndex, const int numRods);
    void validate_rod_stones(const int rods[], const int id, int &rodIndex);
    int get_stones_removed(const int rodStones, const int rodIndex);
void remove_stones(int rods[], const int rodIndex, const int stonesRemoved);
void print_winner_message(const int id);
void switch_turns(int &id);

int main() {
    const int MAX_RODS = 20;                // maximum number of rods for the game
    const int MAX_STONES_PER_ROD = 10;      // maximum number of stones per rod for the game

    /* Prompt and read in the number of rods */
    int numRods = read_num_rods(MAX_RODS);
    cout << endl;

    /* Prompt and read in the number of stones in each rod */
    int *rods = new int[numRods];
    read_rods(rods, numRods, MAX_STONES_PER_ROD);

    /* Print the rod information and current game statistics */
    print_rods(rods, numRods);
    print_stats(rods, numRods);
    cout << endl;

    /* Play the game until all the rods are empty */
    int playerId = 1;
    while (!game_over(rods, numRods)) {
        /* Prompt and read in the current player's next move */
        int rodIndex, stonesRemoved;
        read_player_move(rods, numRods, playerId, rodIndex, stonesRemoved);

        /* Remove the specified number of stones from from the chosen rod */
        remove_stones(rods, rodIndex, stonesRemoved);

        /* Check if somebody won the game */
        if (game_over(rods, numRods)) {
            cout << endl;
            print_winner_message(playerId);
        } else {
            /* Print the rod information and current game statistics */
            print_rods(rods, numRods);
            print_stats(rods, numRods);
            cout << endl;

            /* Switch to the other player's turn */
            switch_turns(playerId);
        }
    }

    /* Free dynamically allocated memory */
    delete[] rods;

    return 0;
}

/**
 * @brief Prompts and reads in the number of rods used in the game. If the number entered is
 * not between 1 and the maximum number of rods, then the procedure displays a warning message
 * and prompts again.
 * 
 * @param maxRods The maximum number of rods for the game
 * @return The number of rods for the current game. 
 */
int read_num_rods(const int maxRods) {
    int numRods;

    cout << "How many rods are in this game: ", cin >> numRods;
    while (numRods < 1 || numRods > maxRods) {
        cout << "Numer of rods must be positive and less than or equal to " << maxRods << endl;
        cout << "Enter number of rods again: ", cin >> numRods;
    }
    
    return numRods;
}

/**
 * @brief Prompts and reads in the number of stones to start for given rod in the game.
 * 
 * @param numStones The number of stones to start on the current rod
 * @param index The index of the choen rod in the list of rods
 * @param maxStones The maximum number of stones per rod for the game
 */
void read_num_stones(int &numStones, const int index, const int maxStones) {
    cout << "How many stones are on rod " << index+1 << ": ", cin >> numStones;
    while (numStones < 1 || numStones > maxStones) {
        cout << "Sorry, the number of stones must be positive and less than or equal to " << maxStones << endl;
        cout << "How many stones are on rod " << index+1 << ": ", cin >> numStones;
    }
}

/**
 * @brief Prompts and reads in the number of stones to start for eacg rod in the game.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 * @param maxStones The maximum number of stones per rod for the game
 */
void read_rods(int rods[], const int numRods, const int maxStones) {
    for (int i = 0; i < numRods; i++) {
        read_num_stones(rods[i], i, maxStones);
    }
}

/**
 * @brief Gets the string representation for a single rod in the game.
 * 
 * @param rodStones The number of stones on the selected rod
 * @return The string representation of the given rod. 
 */
string rod_representation(const int rodStones) {
    string rod_rep;
    for (int i = 0; i < rodStones; i++) {
        rod_rep += '*';
    }
    return  rod_rep;
}

/**
 * @brief Computes the percent of total stones for a single rod in the game.
 * 
 * @param rodStones The number of stones on the selected rod
 * @param totalStones The total number of stones in the current game
 * @return The percent of total stones on the given rod. 
 */
double stones_fraction(const int rodStones, const int totalStones) {
    double ratio = (double)rodStones / totalStones;
    return (ratio * 100);
}

/**
 * @brief Print the information for a single rod in the game.
 * 
 * @param index The index of the choen rod in the list of rods
 * @param rodStones The number of stones on the selected rod
 * @param totalStones The total number of stones in the current game
 */
void print_row(const int index, const int rodStones, const int totalStones) {
    cout << "Rod " << setw(2) << right << index+1 << ": ";
    cout << setw(10) << left << rod_representation(rodStones);
    cout <<  setw(6) << right << "(" << fixed << setprecision(3) << stones_fraction(rodStones, totalStones) << "%)";
    cout << endl;
}

/**
 * @brief Print the information for each rod in the game.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 */
void print_rods(const int rods[], const int numRods) {
    /* Compute the total number of stones currently on the rods */
    int totalStones = 0;
    for (int i = 0; i < numRods; i++) {
        totalStones += rods[i];
    }

    /* Print the information for each rod in the game */
    cout << endl;
    for (int i = 0; i < numRods; i++) {
        print_row(i, rods[i], totalStones);
    }
    cout << endl;
}

/**
 * @brief Prints the rod(s) with the smallest number of stones.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 */
void print_min_stones(const int rods[], const int numRods) {
    /* Find the smallest number of stone currently on a rod */
    int minStones = 10;
    for (int i = 0; i < numRods; i++) {
        int stones = rods[i];
        /* Check if current rod has less stones than current smallest */
        if (stones < minStones) {
            minStones = stones;
        }
    }

    /* Prints the rods that currently contain the smallest number of stones */
    for (int i = 0; i < numRods; i++) {
        /* Check that rod has smallest number of stones */
        if (rods[i] == minStones) {
            cout << "Rod " << i+1 << " has the smallest number of stones with " << minStones << " object(s). " << endl;
        }
    }
}

/**
 * @brief Prints the rod(s) with the largest number of stones.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 */
void print_max_stones(const int rods[], const int numRods) {
    /* Find the largest number of stone currently on a rod */
    int maxStones = 0;
    for (int i = 0; i < numRods; i++) {
        int stones = rods[i];
        /* Check if current rod has more stones than current largest */
        if (stones > maxStones) {
            maxStones = stones;
        }
    }

    /* Prints the rods that currently contain the largest number of stones */
    for (int i = 0; i < numRods; i++) {
        /* Check that rod has largest number of stones */
        if (rods[i] == maxStones) {
            cout << "Rod " << i+1 << " has the largest number of stones with " << maxStones << " object(s). " << endl;
        }
    }
}

/**
 * @brief Prints the average number of stones per rod, but only taking into account rods with
 * at least one stone.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 */
void print_avg_stones(const int rods[], const int numRods) {
    int numNonEmpty = 0;
    double avgStones = 0;

    /* Compute the average number of stones per (non-empty) rod */
    for (int i = 0; i < numRods; i++) {
        int stones = rods[i];
        /* Check that the current rod has stones */
        if (stones > 0) {
            avgStones += stones;
            numNonEmpty++;
        }
    }
    avgStones /= numNonEmpty;

    /* Prints the average number of stones per rod */
    cout << "The average number of stones per rod (i.e., rods with stones) is ";
    cout << fixed << setprecision(2) << avgStones << " stones. " << endl;
}

/**
 * @brief Prints the statistics (smallest number of stones, largest number of stones, and
 * average number of stones) for the current state of teh game.
 * 
 */
void print_stats(const int rods[], const int numRods) {
    print_min_stones(rods, numRods);
    print_max_stones(rods, numRods);
    print_avg_stones(rods, numRods);
}

/**
 * @brief Determines whethere or not one of the players has won the game. A player has won if
 * all the rods are empty.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 * @return True if the game is over (all rods empty), false otherwise.
 */
bool game_over(const int rods[], const int numRods) {
    for (int i = 0; i < numRods; i++) {
        /* Check is current rod has any stones */
        if (rods[i] > 0) {
            return false;
        }
    }
    /* All of the rods are empty */
    return true;
}

/**
 * @brief Prompt and read in a rod selection.
 * 
 * @param id The ID of the current player (1 or 2)
 * @return The ID of the chosen rod. 
 */
int choose_rod(const int id) {
    int rodIndex;
    cout << "Player (" << id << "): Which rod would you like to play? ", cin >> rodIndex;
    return rodIndex;
}

/**
 * @brief Validates the rod selected by the player, i.e. the rod selected must be between 0
 * and n-1 where n is the total number of rods. If the rod selected is invalid, then the
 * procedure displays a warning message and prompts for rod selection again.
 * 
 * @param id The ID of the current player (1 or 2)
 * @param rodIndex The ID of the selected rod
 * @param numRods The number of rods in the current game
 */
void validate_rod_index(const int id, int &rodIndex, const int numRods) {
    while (rodIndex < 1 || rodIndex > numRods) {
        cout << "Invalid rod number. Please try again." << endl;
        rodIndex = choose_rod(id);
    }
}

/**
 * @brief Validates whether the rod selected has at least one stone. If the rod selected is
 * invalid, then the procedure displays a warning message and prompts for rod selection again.
 * 
 * @param rods The array of rods containing stones for the game
 * @param id The ID of the current player (1 or 2)
 * @param rodIndex The ID of the selected rod
 */
void validate_rod_stones(const int rods[], const int id, int &rodIndex) {
    while (rods[rodIndex-1] == 0) {
        cout << "Rod " << rodIndex << " has zero stones. Please select a differnt rod." << endl;
        rodIndex = choose_rod(id);
    }
}

/**
 * @brief Prompt and read in the number of stones to remove from the indicated rod.
 * 
 * @param rodStones The number of stones on the selected rod
 * @param rodIndex The ID of the selected rod
 * @return The number of stones to remove from the selected rod. 
 */
int get_stones_removed(const int rodStones, const int rodIndex) {
    int stonesRemoved;
    cout << "Enter number of stones to remove (" << rodStones << " or less) from rod " << rodIndex << ": ";
    cin >> stonesRemoved;
    return stonesRemoved;
}

/**
 * @brief Prompts and reads in the rod from which to remove stones. If the player inputs an
 * invalid rod ID or chooses a rod with no stones, then the procedure displays a warning
 * message and prompts again. Also prompts and reads in how many stones to remove from the
 * chosen rod. If the player inputs an invalid number of stones, then the procedure displays
 * a warning message and prompts again. The number of stones to remove must be positive and
 * must not exceed the number of stones on teh chosen rod.
 * 
 * @param rods The array of rods containing stones for the game
 * @param numRods The number of rods in the current game
 * @param id The ID of the current player (1 or 2)
 * @param rodIndex The ID of the selected rod
 * @param stonesRemoved The number of stones to remove from the selected rod
 */
void read_player_move(const int rods[], const int numRods, const int id, int &rodIndex, int &stonesRemoved) {
    /* Prompt, read, and validate the players choice of rod to play */
    rodIndex = choose_rod(id);
    validate_rod_index(id, rodIndex, numRods);
    validate_rod_stones(rods, id, rodIndex);

    /* Prompt, read, and validate the number of stones to remove from the chosen rod */
    int rodStones = rods[rodIndex-1];
    stonesRemoved = get_stones_removed(rodStones, rodIndex);
    while (stonesRemoved < 1 || stonesRemoved > rodStones) {
        if (stonesRemoved < 1) {
            cout << "Number of stones you can remove must be positive. Try again." << endl;
        } else if (stonesRemoved > rodStones) {
            cout << "Can only remove up to " << rodStones << " object(s). Please try again." << endl;
        }
        stonesRemoved = get_stones_removed(rodStones, rodIndex);
    }
}

/**
 * @brief Modify the array of rods by subtracting the specified number of stones from the
 * chosen rod.
 * 
 * @param rods The array of rods containing stones for the game
 * @param rodIndex The ID of the selected rod
 * @param stonesRemoved The number of stones to remove from the selected rod
 */
void remove_stones(int rods[], const int rodIndex, const int stonesRemoved) {
    rods[rodIndex-1] -= stonesRemoved;
}

/**
 * @brief Print a message congratulating the winner.
 * 
 * @param id The ID of the current player (1 or 2)
 */
void print_winner_message(const int id) {
    cout << "Congratulations! Player " << id << " wins." << endl;
}

/**
 * @brief Switch the turn to the player.
 * 
 * @param id The ID of the current player (1 or 2)
 */
void switch_turns(int &id) {
    id = (id % 2) + 1;
}
