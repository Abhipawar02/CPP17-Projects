#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

// List of words to be used in the game
const std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "peach", "pineapple", "raspberry", "strawberry", "watermelon"};

// Function to generate a random word from the list
std::string getRandomWord()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, words.size() - 1);
    return words[distr(gen)];
}

int main()
{
    const std::string wordToGuess = getRandomWord(); // Generate random word from the list
    std::string guessedLetters(wordToGuess.length(), '_'); // Set up blank word to display to user

    int numGuesses = 0;
    const int maxGuesses = 6; // Set maximum number of guesses

    std::cout << "Welcome to Hangman!\n\n";
    std::cout << "The word has " << wordToGuess.length() << " letters.\n\n";

    do {
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        bool correctGuess = false;
        for (int i = 0; i < wordToGuess.length(); ++i) {
            if (wordToGuess[i] == guess) {
                guessedLetters[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            std::cout << "Correct!\n\n";
        } else {
            std::cout << "Incorrect!\n\n";
            numGuesses++;
        }

        std::cout << "Current word: " << guessedLetters << "\n";
        std::cout << "Guesses remaining: " << maxGuesses - numGuesses << "\n\n";
    } while (guessedLetters != wordToGuess && numGuesses < maxGuesses);

    if (guessedLetters == wordToGuess) {
        std::cout << "Congratulations! You guessed the word.\n";
    } else {
        std::cout << "Sorry, you ran out of guesses. The word was: " << wordToGuess << "\n";
    }

    return 0;
}
