#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
// Stack for storing operands
int stack[MAX];
int top = -1;
// Function to push to the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}
// Function to pop from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
// Function to generate machine code (here represented as simple assembly)
void generate_machine_code(char operator) {
    int operand2 = pop();
    int operand1 = pop();
    switch (operator) {
        case '+':
            printf("ADD R0, R1, R2\n");  // R0 = R1 + R2 (simple example)
            break;
        case '-':
            printf("SUB R0, R1, R2\n");  // R0 = R1 - R2
            break;
        case '*':
            printf("MUL R0, R1, R2\n");  // R0 = R1 * R2
            break;
        case '/':
            printf("DIV R0, R1, R2\n");  // R0 = R1 / R2
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}
// Function to evaluate postfix expression
void evaluate_postfix(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            // If the character is a digit, push it to the stack
            push(expr[i] - '0');
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // If the character is an operator, pop two operands and apply the operator
            generate_machine_code(expr[i]);
        }}}
int main() {
    char postfix_expr[MAX];  
    printf("Enter a postfix expression: ");
    scanf("%s", postfix_expr);
    // Evaluate the postfix expression and generate machine code
    evaluate_postfix(postfix_expr);
    return 0;
}
