%{  
#include<stdio.h>  
#include<ctype.h>  
#include<stdlib.h>  
#include<string.h>  
%}  
%token num  
%left '+' '-'  
%left '*' '/'  
%%  
st: st expr '\n' {printf("Valid");}  
|st '\n'  
|  
|error '\n' {printf("INVALID");}  
;  
expr: num  
|expr '+' expr  
|expr ‘*’ expr 
|expr '/' expr  
%%  
main() {  
printf(" ENTER AN EXPRESSION TO VALIDATE");  
yyparse();  
}  
yylex()  
{  
int ch; 

while((ch=getchar())==' ');  
if(isdigit(ch)|ch=='.') {  
ungetc(ch,stdin);  
scanf("%lf",&yylval);  
return num;  
}  
return ch;  
}  
yyerror(char *s)  
{  
printf("%S",s);  
}
