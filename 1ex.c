#include <stdio.h>
#include <ctype.h>
#include <string.h>
// Function to check if a character is a valid identifier start
int isIdentifierStart(char c) {
    return isalpha(c) || c == '_';
}
// Function to check if a character is valid in an identifier
int isIdentifierPart(char c) {
    return isalnum(c) || c == '_';
}
int main() {
    char input[100];
    printf("Enter a string of code: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0'; // Remove trailing newline
    }
    char token[100];
    int i = 0, j = 0;
    printf("\nTokens:\n");
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++; // Skip whitespace
            continue;
        }
        // Clear token buffer
        j = 0;
        // Handle identifiers
        if (isIdentifierStart(input[i])) {
            while (isIdentifierPart(input[i])) {
                token[j++] = input[i++];
            }
         token[j] = '\0';
            printf("Identifier: %s\n", token);
        }
        // Handle constants
        else if (isdigit(input[i])) {
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Constant: %s\n", token);
        }
        // Skip other characters silently
        else {
            i++;
        }   }
    return 0;
}
