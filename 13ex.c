#include <stdio.h>
#include <string.h>
int main() {
    char code[500];
    printf("Enter C code:\n");
    fgets(code, sizeof(code), stdin);
    // Check for 'for' loop
    if (strstr(code, "for") != NULL) {
        printf("It contains a 'for' loop.\n");
    }
    // Check for 'while' loop
    else if (strstr(code, "while") != NULL) {
        printf("It contains a 'while' loop.\n");
    }
    // Check for 'if-else' statement
    else if (strstr(code, "if") != NULL && strstr(code, "else") != NULL) {
        printf("It contains an 'if-else' statement.\n");
    }
    // Check for 'switch-case' statement
    else if (strstr(code, "switch") != NULL && strstr(code, "case") != NULL) {
        printf("It contains a 'switch-case' statement.\n");
    }
    else {
        printf("No valid control structure found.\n");
    }
    return 0;
}
