#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char value;
    struct Node *left, *right;
} Node;

Node* createNode(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* parseExpression(const char** expr) {
    if (**expr == '\0') 
    return NULL;
    char current = **expr;
    (*expr)++;
    if (isdigit(current)) 
    return createNode(current);

    Node* node = createNode(current);
    node->left = parseExpression(expr);
    node->right = parseExpression(expr);
    return node;
}

void printAST(Node* root) {
    if (!root) 
    return;
    printf("%c ", root->value);
    printAST(root->left);
    printAST(root->right);
}

int main() {
    char expression[100];
    printf("Enter the arithmetic expression in prefix notation: ");
    scanf("%s", expression);

    const char* exprPtr = expression;
    Node* ast = parseExpression(&exprPtr);

    printf("Pre-order traversal of the AST: ");
    printAST(ast);
    printf("\n");
    return 0;
}
