#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "word-provider.h"

using namespace std;

char Uppercase(char c);
void Lowercase(string& str);

int main() {
    WordProvider wordProvider;
    string guess;
    string word = wordProvider.getRandomWord(); // Replaced with a hardcoded word for testing
    int guesses = 1;
    const int maxGuesses = 6;

    int wordLength = word.length();

    cout << "Guess the " << wordLength << " letter word and enter q to quit." << endl;
    while (guesses <= maxGuesses) {
        cout << "Enter your guess: ";
        cin >> guess;
        Lowercase(guess);

        if (guess[0] == 'q') {
            break;
        }
        if (!wordProvider.CheckForValidWord(guess)) {
            cout << "The word you entered is not a valid word." << endl;
            continue;
        }
        if (guess.length() != wordLength) {
            cout << "Your guess does not match the number (" << wordLength << ") of characters in the word." << endl;
            continue;
        }
        if (strcasecmp(guess.c_str(), word.c_str()) == 0) {
            cout << "You guessed correctly in " << guesses << " attempts!" << endl;
            break;
        }
        int match = 0;
        string buffer(wordLength, '_');
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess[i]) {
                buffer[i] = Uppercase(guess[i]);
                match++;
            } else {
                for (int j = 0; j < wordLength; j++) {
                    if (guess[i] == word[j]) {
                        buffer[i] = guess[i];
                    }
                }
            }
        }
        cout << "You guessed " << match << " letters in the correct spot." << endl;
        cout << "Your guess was: " << guess << endl;
        cout << "Your result is: " << buffer << endl;
        guesses++;
    }
    if (guesses > maxGuesses) {
        cout << "You've used all your guesses. The word was: " << word << endl;
    }
    return 0;
}

char Uppercase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

void Lowercase(string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
