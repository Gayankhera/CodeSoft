#include <iostream>  
#include <cstdlib>   
#include <ctime>    

using namespace std;


int main() {
    srand(static_cast<unsigned>(time(0)));

    const int min = 1;    
    const int max = 100; 
    int numbertoguess = rand() % (max - min + 1) + min;

    int userguess = 0;       
    int numberOftries = 0;    
    bool hasguessedcorrectly = false; 

   cout << "Welcome to the Number Guessing Game!\n";
   cout << "I am thinking of a number between " << min << " and " << max << ".\n";

    while (!hasguessedcorrectly) {
        cout << "Enter your guess: ";
        cin >> userguess;  
        numberOftries++;      

        if (userguess < min || userguess > max) {
            cout << "Please guess a number between " << min << " and " <<max << ".\n";
        }
        else if (userguess < numbertoguess) {
            cout << "Too low! Try again.\n";
        }
        else if (userguess > numbertoguess) {
            cout << "Too high! Try again.\n";
        }
        else {
            hasguessedcorrectly = true;  
            cout << "Congratulations! You've guessed the number in " << numberOftries << " tries.\n";
        }
    }

    return 0;  
}