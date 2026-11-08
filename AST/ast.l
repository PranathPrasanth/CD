%{
#include "y.tab.h"
#include <string.h>
%}

%%

[a-zA-Z0-9]+    { yylval.s = strdup(yytext); return ID; }
[-+*/()]        { return yytext[0]; }
\n              { return 0; }
[ \t]+          ;
.               { return yytext[0]; }

%%

int yywrap(void) { return 1; }
