#include <stdio.h>
#include <string.h>
void eliminateLeftRecursion(char *nonTerminal, char productions[][50], int n) {
    char newNonTerminal[50];     
    sprintf(newNonTerminal, "%s", nonTerminal);  // Create new non-terminal (A')
    printf("Original Grammar:\n");
    for (int i = 0; i < n; i++) {
        printf("%s → %s\n", nonTerminal, productions[i]);
    }
    printf("\nEliminated Left Recursion Grammar:\n");
    // Step 1: Create productions for the new non-terminal (A')
    printf("%s → ", nonTerminal);
    for (int i = 0; i < n; i++) {
        // First production: βA'
        if (i == n - 1) {
            printf("%s\n", productions[i]);
        } else {
            printf("%s | ", productions[i]);
        }
    }
    printf("%s' → ", newNonTerminal);
    // Step 2: Create productions for A'
    for (int i = 0; i < n; i++) {
        // Second production: αA' | ε
        if (strchr(productions[i], nonTerminal[0]) != NULL) {
            printf("%s%s' | ", productions[i] + 1, newNonTerminal);
        }
    }
    printf("ε\n"); // Adding the epsilon production for A'
}
int main() {
    char nonTerminal[50];
    int n;
    char productions[n][50];
    printf("Enter the non-terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter the number of production rules: ");
    scanf("%d", &n);  
    printf("Enter the production rules (one per line):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }
    eliminateLeftRecursion(nonTerminal, productions, n);
    return 0;
}