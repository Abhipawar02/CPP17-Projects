#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd; // Seed the random number generator
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 100);

    const int secretNumber = distr(gen); // Generate random number between 1 and 100

    int guess = 0;
    int numGuesses = 0;

    cout << "Welcome to the Guessing Game!\n\n";

    do {
        cout << "Enter your guess (1-100): ";
        cin >> guess;
        numGuesses++;

        if (guess < secretNumber) {
            cout << "Too low, try again.\n\n";
        } else if (guess > secretNumber) {
            cout << "Too high, try again.\n\n";
        } else {
            cout << "Congratulations! You guessed the number in " << numGuesses << " guesses!\n\n";
        }
    } while (guess != secretNumber);

    return 0;
}
