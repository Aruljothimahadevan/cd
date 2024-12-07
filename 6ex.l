%{
#include<stdio.h>
#include<math.h>
#include"y.tab.h"
%}
%%
([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {yylval.dval=atof(yytext); return NUMBER;}
MEM {return MEM;}
[\t];
\$ {return 0;}
\n {return yytext[0];}
. {return yytext[0];}
%%
