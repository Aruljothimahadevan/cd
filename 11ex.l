%{
#include "y.tab.h"
%}
%%
[A-Z][a-zA-Z0-9]{5}    { return STATEMENT; }  // Recognizes a pattern starting with an uppercase letter followed by 5 alphanumeric characters.
[ \t\n]    ;   // Ignore spaces, tabs, and newlines.
.       { return yytext[0]; }  // Return the character as is if not a valid statement.
%%
int yywrap(void) {
    return 1;
}
