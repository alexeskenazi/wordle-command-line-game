#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class WordProvider {
public:
    string getRandomWord() {
        string filename = "valid-wordle-words.txt";
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return "";
        }

        string word, selectedWord;
        int count = 0;
        srand(time(0));  // Seed random number generator

        while (getline(file, word)) {
            count++;
            if (rand() % count == 0) { // Probability 1/count of replacing the current selection
                selectedWord = word;
            }
        }

        file.close();
        return selectedWord;
    }

    bool CheckForValidWord(const string& wordToCheck) {
        string filename = "valid-wordle-words.txt";
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }

        string word;
        while (getline(file, word)) {
            if (word == wordToCheck) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }
};


