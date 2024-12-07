%{
#include <stdio.h>
#include <string.h>
// List of C reserved keywords
char *keywords[] = {
    "int", "float", "double", "char", "if", "else", "while", "for", "return", "switch", "case", "default", "break", "continue", "void"
};
%}
%%
[ \t\n]+             { /* Skip whitespace */ }
"int"|"float"|"double"|"char"|"if"|"else"|"while"|"for"|"return"|"switch"|"case"|"default"|"break"|"continue"|"void" {
                        printf("Reserved word: %s\n", yytext);
                    }
[0-9]+               { printf("Number: %s\n", yytext); }
[0-9]+\.[0-9]+       { printf("Floating point number: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Variable: %s\n", yytext); }
"+"|"-"|"*"|"/"|"%"  { printf("Operator: %s\n", yytext); }
"="|"<"|">"|"=="|"<="|">="|"!=" { printf("Operator: %s\n", yytext); }
"(" | ")" | "{" | "}" | ";" { printf("Punctuation: %s\n", yytext); }
.                      { /* Ignore other characters */ }
%%
int main() {
    printf("Enter a C program to scan keywords, variables, and operators:\n");
    yylex();  // Call the lexical analyzer
    return 0;
}
