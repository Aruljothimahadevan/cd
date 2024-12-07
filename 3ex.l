%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[ \t\n]+                ;   					 /* Ignore whitespace */
"if"|"else"|"while"|"int"|"return" { printf("KEYWORD: %s\n", yytext); }
[0-9]+                  { printf("NUMBER: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("IDENTIFIER: %s\n", yytext); }
"+"|"-"|"*"|"/"         { printf("OPERATOR: %s\n", yytext); }
"="                     { printf("ASSIGNMENT OPERATOR: %s\n", yytext); }
";"                     { printf("SEMICOLON: %s\n", yytext); }
.                       { printf("UNKNOWN TOKEN: %s\n", yytext); }
%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input-file>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    return 0;
}
