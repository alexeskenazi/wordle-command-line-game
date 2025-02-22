#include <stdio.h>
#include <string.h>

char Uppercase(char c);
void Lowercase(char* str);

int main()  {
    char guess[100];
    char word[]= "chain";
    int wordLength = strlen(word);
    int guesses = 1;
    
    printf("Guess the %d letter word and enter q to quit.\n", wordLength);
    while(1)    {
        printf("Enter your guess: ");
        scanf("%s", guess);
        Lowercase(guess);
        
        if(guess[0]== 'q')    {
            break;
        
        }
        if (strlen(guess) != wordLength)  {
            printf("Your guess does not match the number (%d) of characters in the word.\n", strlen(word));
            continue;
            
        }
        if (strcasecmp(guess, word) == 0){
            printf("You guessed correctly in %d attempts!", guesses);
            break;
        }
        int match = 0;
        char buffer[100];
        for(int i = 0; i<wordLength; i++){
            buffer[i] = '_';
            buffer[i+1] = 0;
            if(word[i] == guess[i]){
                buffer[i] = Uppercase(guess[i]);
                match++;
            
            }
            else{
                for (int j = 0; j<wordLength; j++) {
                    if(guess[i] == word[j]){
                        buffer [i] = guess[i];
                        
                    }
                }
            }
        }
        printf("You guessed %d # of letters in the correct spot.\n",match);
        printf("Your guess was: %s\n", guess); 
        printf("Your result is: %s\n", buffer);   
        guesses++;
        
    }
    return 0;
}
//Write a function that takes a character and returns the uppercase version. (Upper)
char Uppercase(char c) {
    if(c >= 'a'){
        return c - 32;
    }
    return c;
}

void Lowercase(char* str){
    for(int i = 0; i<strlen(str); i++) {
        if(str[i] <= 'Z' && str[i] >='A') {
            str[i]+=32;
        }

    }
 }

