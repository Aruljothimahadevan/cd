#include <stdio.h>
#include <string.h>
struct Operation {
    char l;  // Left-hand side (variable)
    char r[20];  // Right-hand side (expression)
} op[10], pr[10];
void eliminateDeadCode(int *n) {
    int i, j, z = 0;
    for(i = 0; i < *n - 1; i++) {
        char temp = op[i].l;
        for(j = 0; j < *n; j++) {
            if (strchr(op[j].r, temp)) {
                pr[z].l = op[i].l;
                strcpy(pr[z].r, op[i].r);
                z++;
            }}}
    pr[z].l = op[*n - 1].l;
    strcpy(pr[z].r, op[*n - 1].r);
    *n = z + 1;  // Update the number of expressions after elimination
}
void eliminateCommonSubexpression(int *n) {
    int i, j;
    for(i = 0; i < *n; i++) {
        for(j = i + 1; j < *n; j++) {
            if (strcmp(pr[i].r, pr[j].r) == 0 && pr[i].l != pr[j].l) {
                pr[j].l = pr[i].l;  // Replace with first occurrence
                strcpy(pr[j].r, pr[i].r);
            }}}}
void constantFolding() {
    // Example of constant folding: Replace constant expressions like `10+20` with `30`
    for (int i = 0; i < 10; i++) {
        // This is a simplified check for addition (you can add more operations)
        if (strchr(pr[i].r, '+')) {
            int a, b;
            if (sscanf(pr[i].r, "%d+%d", &a, &b) == 2) {
                snprintf(pr[i].r, sizeof(pr[i].r), "%d", a + b);
            }}}}
void loopUnrollingExample() {
    // A basic example: Calculate sum of an array using loop unrolling
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    // Unrolled loop: Sum 2 elements at a time
    for (int i = 0; i < n; i += 2) {
        sum += arr[i];
        if (i + 1 < n) {
            sum += arr[i + 1];
        }}
    printf("Sum of array elements (after loop unrolling): %d\n", sum);
}
void displayOperations(int n) {
    printf("\nOptimized Code:\n");
    for (int i = 0; i < n; i++) {
        if (pr[i].l != '\0') {
            printf("%c = %s\n", pr[i].l, pr[i].r);
     } }}
int main() {
    int n;
    printf("Enter the number of operations: ");
    scanf("%d", &n);
    // Input operations (left and right sides of equations)
    for (int i = 0; i < n; i++) {
        printf("Left: ");
        scanf(" %c", &op[i].l);  // Use space before %c to capture newline
        printf("Right: ");
        scanf("%s", op[i].r);  // Read the right-hand side expression
    }
    // Perform optimization techniques
    printf("\nIntermediate Code:\n");
    for (int i = 0; i < n; i++) {
        printf("%c = %s\n", op[i].l, op[i].r);
    }
    eliminateDeadCode(&n);  // Remove dead code
    eliminateCommonSubexpression(&n);  // Eliminate common subexpressions
    constantFolding();  // Perform constant folding
    // Display optimized code
    displayOperations(n);
    // Example of loop unrolling
    loopUnrollingExample();
    return 0;
}
