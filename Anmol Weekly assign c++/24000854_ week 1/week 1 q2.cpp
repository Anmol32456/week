/*2.	 Write a C++ program to implement a number guessing game with different difficulty levels.
Easy difficulty ranges from 1-8, medium from 1-30, hard from 1-50.Then,generate a random number to check if the guess is correct based on the user's selection. 
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int level, max;
    int number, guess;


    cout << "Choose difficulty level:" << endl;
    cout << "1. Easy (1 to 8)" << endl;
    cout << "2. Medium (1 to 30)" << endl;
    cout << "3. Hard (1 to 50)" << endl;
    cout << "Enter 1, 2 or 3: ";
    cin >> level;

    if (level == 1)
        max = 8;
    else if (level == 2)
        max = 30;
    else if (level == 3)
        max = 50;
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    number = rand() % max + 1;  

    cout << "Guess the number between 1 and " << max << ": ";
    cin >> guess;

    if (guess == number)
        cout << "You guessed it right! ??" << endl;
    else
        cout << "Wrong! The correct number was " << number << "." << endl;

    return 0;
}

