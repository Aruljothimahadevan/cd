#include <stdio.h>
#include <string.h>
void generateAssembly(char *tac) {
    char result[10], op1[10], op2[10], op;
    // Parsing the three address code of the form: result = op1 op operator op2
    if (sscanf(tac, "%s = %s %c %s", result, op1, &op, op2) == 4) {
        printf("MOV R1, %s\t; R1 = %s\n", op1, op1);  // Load first operand into R1
        if (op == '+')
            printf("ADD R1, %s\t; R1 = R1 + %s\n", op2, op2);  // Add second operand
        else if (op == '-')
            printf("SUB R1, %s\t; R1 = R1 - %s\n", op2, op2);  // Subtract second operand
        
        printf("MOV %s, R1\t; %s = R1\n", result, result);  // Store result in destination
    }
}
int main() {
    char tac[100];
    // Get the Three Address Code input
    printf("Enter Three Address Code (Example: t1 = a + b):\n");
    fgets(tac, sizeof(tac), stdin);
    // Remove newline character
    tac[strcspn(tac, "\n")] = 0;
    // Generate Assembly
    generateAssembly(tac);
    return 0;
}
