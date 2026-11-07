%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token LETTER DIGIT NL

%%

start : var NL { printf("Valid variable\n"); exit(0); }
      ;

var   : LETTER rest
      ;

rest  : LETTER rest
      | DIGIT rest
      | /* empty */
      ;

%%

void yyerror(const char *s) {
    printf("Invalid variable\n");
    exit(0);
}

int main() {
    printf("Enter a variable: ");
    yyparse();
    return 0;
}

/*
================== COMMANDS ==================
gedit variable.l variable.y &
yacc -d variable.y
lex variable.l
gcc y.tab.c lex.yy.c -o variable
./variable

================== SAMPLE I/O ==================
Input:  myVar1
Output: Valid variable

Input:  1myVar
Output: Invalid variable
================================================
*/
