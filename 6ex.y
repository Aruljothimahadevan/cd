%{
#include<stdio.h>
#include<math.h>
double memvar;
%}
%union {
double dval;
}
%token<dval> NUMBER
%token<dval> MEM
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%type<dval> expression
%%
start: statement '\n'
     | start statement '\n';

statement: MEM '=' expression { memvar = $3; }
         | expression { printf("answer=%g\n", $1); };

expression: expression '+' expression { $$ = $1 + $3; }
          | expression '-' expression { $$ = $1 - $3; }
          | expression '*' expression { $$ = $1 * $3; }
          | expression '/' expression { if ($3 == 0) yyerror("divide by zero");
                                         else $$ = $1 / $3; }
          | '-' expression %prec UMINUS { $$ = -$2; }
          | '(' expression ')' { $$ = $2; }
          | NUMBER { $$ = $1; }
          | MEM { $$ = memvar; };
%%
int main(void) {
    printf("Enter the expression: ");
    yyparse();
    printf("\n\n");
    return 0;
}
int yywrap() {
    return 0;
}
int yyerror(char *error) {
    printf("%s\n", error);
    return 0;
}
