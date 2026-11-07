%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%
start:
      expr '\n'       { printf("Result = %d\n", $1); exit(0); }
    ;

expr:
      expr '+' expr   { $$ = $1 + $3; }
    | expr '-' expr   { $$ = $1 - $3; }
    | expr '*' expr   { $$ = $1 * $3; }
    | expr '/' expr   { 
                        if ($3 == 0) {
                            printf("Error: Division by zero\n");
                            exit(0);
                        }
                        $$ = $1 / $3;
                      }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'    { $$ = $2; }
    | NUMBER          { $$ = $1; }
    ;
%%

void yyerror(const char *s) {
    printf("Invalid Expression\n");
    exit(0);
}

int main(void) {
    printf("Enter expression: ");
    yyparse();
    return 0;
}

/*
COMMANDS TO RUN (DEBIAN LINUX):
$ bison -d -y calc.y
$ flex calc.l
$ gcc y.tab.c lex.yy.c -o calc
$ ./calc

SAMPLE I/O:
Input:
Enter expression: 10 + 5 * 2
Output:
Result = 20
*/
