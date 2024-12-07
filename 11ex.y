%{
#include <stdio.h>
#include <stdlib.h>
%}
%token STATEMENT
%%
input:
    statements
    ;
statements:
    statement
    | statements statement
    ;
statement:
    STATEMENT {
        printf("Valid statement: %s\n", yytext);
    }
    ;
%%
int main(void) {
    printf("Enter a statement: ");
    yyparse();
    return 0;
}
int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
