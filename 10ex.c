#include <stdio.h>
#include <string.h>
struct IntermediateCode {
    char left;    // Left side variable
    char right[20];  // Right side expression
} intermediateCode[10];
int registerCount = 0;  // To track available registers
// Function to generate machine code from intermediate code
void generateMachineCode(int n) {
    printf("\nMachine Code:\n");
    for (int i = 0; i < n; i++) {
        char reg = 'R' + registerCount++;  // Assign a new register
        char *operation = intermediateCode[i].right;
        printf("// Intermediate Code: %c = %s\n", intermediateCode[i].left, intermediateCode[i].right);
        // Simulate machine code for each operation (only ADD and basic operations for simplicity)
        if (strchr(operation, '+')) {
            char var1, var2;
            sscanf(operation, "%c+%c", &var1, &var2);  // Extract variables in addition
            // Load the first operand (var1) into a register
            printf("LOAD %c      // Load %c into register\n", var1, var1);
            printf("ADD %c       // Add %c to register\n", var2, var2);
        }
        else if (strchr(operation, '-')) {
            char var1, var2;
            sscanf(operation, "%c-%c", &var1, &var2);  // Extract variables in subtraction
            // Load the first operand (var1) into a register
            printf("LOAD %c      // Load %c into register\n", var1, var1);
            printf("SUB %c       // Subtract %c from register\n", var2, var2);
        }
        else if (strchr(operation, '*')) {
            char var1, var2;
            sscanf(operation, "%c*%c", &var1, &var2);  // Extract variables in multiplication
            // Load the first operand (var1) into a register
            printf("LOAD %c      // Load %c into register\n", var1, var1);
            printf("MUL %c       // Multiply register by %c\n", var2, var2);
        }
        else if (strchr(operation, '/')) {
            char var1, var2;
            sscanf(operation, "%c/%c", &var1, &var2);  // Extract variables in division
            // Load the first operand (var1) into a register
            printf("LOAD %c      // Load %c into register\n", var1, var1);
            printf("DIV %c       // Divide register by %c\n", var2, var2);
        }
        // Store the result into the left-hand side variable
        printf("STORE %c     // Store result in %c\n\n", reg, intermediateCode[i].left);
    }
}
int main() {
    int n;
    printf("Enter the number of operations: ");
    scanf("%d", &n);
    // Input intermediate code operations
    for (int i = 0; i < n; i++) {
        printf("Enter the left-hand side variable (single character): ");
        scanf(" %c", &intermediateCode[i].left);  // Space before %c to consume any leftover newline
        printf("Enter the right-hand side expression (e.g., a+b): ");
        scanf("%s", intermediateCode[i].right);
    }
    // Generate machine code from the input intermediate code
    generateMachineCode(n);
    return 0;
}
