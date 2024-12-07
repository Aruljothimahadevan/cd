#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_RULES 5
#define MAX_TERMINALS 5
// Define terminal symbols
typedef enum { ID, PLUS, STAR, LPAREN, RPAREN, END } TokenType;
// Structure to represent a rule in the grammar
typedef struct {
    char* left;  // Non-terminal (e.g., E)
    char* right; // Right-hand side of the production (e.g., T + E)
} Rule;
// Parsing table: a 2D array of rules
Rule parseTable[3][MAX_TERMINALS];
// Tokenize input string into tokens (ID, PLUS, STAR, etc.)
TokenType getNextToken(const char** input) {
    while (**input == ' ') (*input)++; // Skip spaces
    if (**input == '\0') return END;
    if (**input == '+') { (*input)++; return PLUS; }
    if (**input == '*') { (*input)++; return STAR; }
    if (**input == '(') { (*input)++; return LPAREN; }
    if (**input == ')') { (*input)++; return RPAREN; }
    if (isalnum(**input)) { (*input)++; return ID; }
    return END;
}
// Initialize the parsing table
void initParsingTable() {
    // Rules for parsing E -> T | E + T
    parseTable[0][ID] = (Rule) {"E", "T"};
    parseTable[0][LPAREN] = (Rule) {"E", "T"};  
    // Rules for parsing T -> F | T * F
    parseTable[1][ID] = (Rule) {"T", "F"};
    parseTable[1][LPAREN] = (Rule) {"T", "F"};
    // Rules for parsing F -> id
    parseTable[2][ID] = (Rule) {"F", "id"};
}
// Print a production rule
void printRule(Rule rule) {
    printf("%s -> %s\n", rule.left, rule.right);
}
// Simple parser function
void parse(const char* input) {
    const char* ptr = input;
    TokenType token = getNextToken(&ptr);
    // Start with the start symbol E
    Rule stack[MAX_RULES];
    int top = -1;
    // Push the start rule E -> T onto the stack
    stack[++top] = parseTable[0][token];
    while (top >= 0) {
        Rule currentRule = stack[top--];
        printf("Expanding: ");
        printRule(currentRule);
        // Push right-hand side of rule onto stack
        for (int i = 0; currentRule.right[i] != '\0'; i++) {
            if (currentRule.right[i] == 'i') {  // for 'id'
                stack[++top] = parseTable[2][ID]; // id -> id
            } else if (currentRule.right[i] == 'T') {
                stack[++top] = parseTable[1][ID]; // T -> F
            } else {
                printf("Syntax error: unexpected symbol %c\n", currentRule.right[i]);
            }
        }
        // Get the next token from input
        token = getNextToken(&ptr);
    }
}
int main() {
    // Initialize the parsing table
    initParsingTable();
    // Test input: "id + id * id"
    const char* input = "id + id * id";
    parse(input);
    return 0;
}
