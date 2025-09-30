// WAP in C, Take name from user and its favorite number & word and print that word 3 times. In last write Goodbye message.

#include <stdio.h>   // For printf and scanf
#include <string.h>  // For string handling

int main() {
    char name[50];
    int favNumber;
    char favWord[50];

    // Ask user for their name
    printf("What's your name? ");
    scanf("%s", name);  // Takes input until first space
    printf("Hello, %s! Nice to meet you.\n", name);

    // Ask for favorite number
    printf("\nWhat's your favorite number? ");
    scanf("%d", &favNumber);
    printf("Did you know %d doubled is %d?\n", favNumber, favNumber * 2);

    // Ask for favorite word
    printf("\nWhat's your favorite word? ");
    scanf("%s", favWord);
    printf("%s %s %s\n", favWord, favWord, favWord);

    // Goodbye message
    printf("\nGoodbye, %s! See you next time.\n", name);

    return 0;
}