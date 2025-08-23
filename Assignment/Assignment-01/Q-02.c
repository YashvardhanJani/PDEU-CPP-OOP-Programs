// Scan a sentence from the user and find: number of vowels, consonants and words.

#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int vowels = 0, consonants = 0, words = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);  // Read full sentence including spaces

    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]);  // Convert to lowercase for easy comparison

        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (ch == ' ' ||  ch == '\t') {
            words++;
        }
    }

    // If the sentence is not empty, add 1 to word count
    if (sentence[0] != '\n')
        words++;

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Words: %d\n", words);

    return 0;
}