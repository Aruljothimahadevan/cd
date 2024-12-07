%{
#include <stdio.h>
#include <string.h>
%}
%option noyywrap
// Define keywords
%define YY_KEYWORDS if|else|while|return
%%
/\*[^*]*\*+([^/*][^*]*\*+)*/    { printf("Multi-line comment: %s\n", yytext); }  // Match multi-line comments
// Single-line comments
"//".*                             { printf("Single-line comment: %s\n", yytext); }  // Match single-line comments
// Operators
"+"                                { printf("Operator: %s\n", yytext); }
"-"                                { printf("Operator: %s\n", yytext); }
"*"                                { printf("Operator: %s\n", yytext); }
"/"                                { printf("Operator: %s\n", yytext); }
"="                                { printf("Operator: %s\n", yytext); }
"=="                               { printf("Operator: %s\n", yytext); }
// Keywords
"if"                                { printf("Keyword: %s\n", yytext); }
"else"                              { printf("Keyword: %s\n", yytext); }
"while"                             { printf("Keyword: %s\n", yytext); }
"return"                            { printf("Keyword: %s\n", yytext); }
// Identifiers (variable names, function names, etc.)
[a-zA-Z_][a-zA-Z0-9_]*             { printf("Identifier: %s\n", yytext); }
// Numbers
[0-9]+                             { printf("Number: %s\n", yytext); }
// Ignore whitespace and newline
[ \t\n]                            { /* Ignore spaces and newlines */ }
// Catch any other character
.                                  { printf("Unknown character: %s\n", yytext); }
%%
int main() {
    printf("Enter an expression: ");
    yylex();  // Start scanning the input
    return 0;
}
