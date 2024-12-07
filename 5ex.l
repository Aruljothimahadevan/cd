%{
#include "y.tab.h"
%}

%%
[a-zA-Z]    { return LETTER; }
[0-9]       { return DIGIT; }
[ \t\n]     { /* Ignore whitespace */ }
.           { return yytext[0]; }
%%
