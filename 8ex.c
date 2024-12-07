#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// Function to check if a string is a valid integer
int is_valid_integer(const char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Not a valid integer
        }  }
    return 1; // Valid integer
}
int main() {
    char num1[25], num2[25];
    // Input: Prompt user to enter two numbers
    printf("Enter the two numbers: ");
    scanf("%s %s", num1, num2);
    // Validate inputs
    if (!is_valid_integer(num1) || !is_valid_integer(num2)) {
        printf("Type mismatch\n");
    } else {
        // Convert to integers and compute sum
        int sum = atoi(num1) + atoi(num2);
        printf("Sum: %d\n", sum);
    }
    return 0;
}
