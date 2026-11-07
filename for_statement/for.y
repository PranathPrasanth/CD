%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token FOR LE GE EQ NE INC DEC ID NUM

%%

stmt : FOR '(' init ';' cond ';' upd ')' {
         printf("Valid FOR loop\n");
         exit(0);
     }
     ;

init : ID '=' expr
     ;

cond : expr relop expr
     ;

relop : '<' | '>' | LE | GE | EQ | NE
      ;

upd : ID INC
    | ID DEC
    | ID '=' expr
    ;

expr : expr '+' term
     | expr '-' term
     | term
     ;

term : ID
     | NUM
     ;

%%

int main(void) {
    printf("Enter FOR loop expression: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid FOR loop\n");
    exit(0);
}

/*
--------------------------------------------------
DEBIAN COMMANDS TO COMPILE AND RUN:
$ lex for.l
$ yacc -d for.y
$ gcc y.tab.c lex.yy.c -o for_parser
$ ./for_parser

SAMPLE INPUT / OUTPUT:
Enter FOR loop expression: for(i=0;i<10;i++)
Valid FOR loop
--------------------------------------------------
*/
