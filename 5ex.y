%{
#include <stdio.h>
#include <ctype.h>
int yylex();
void yyerror(const char *s);
%}
%token LETTER DIGIT
%%
variable: LETTER var_tail { printf("Valid variable name\n"); }
        ;
var_tail: /* empty */ 
        | LETTER var_tail 
        | DIGIT var_tail
        ;
%%
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
int main() {
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}
