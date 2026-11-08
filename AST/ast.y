%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char *v;
    struct node *l, *r;
} node;

node* mknode(char *v, node *l, node *r) {
    node *n = malloc(sizeof(node));
    n->v = strdup(v);
    n->l = l;
    n->r = r;
    return n;
}

void printTree(node *t, int d) {
    if (!t) return;

    for (int i = 0; i < d; i++) printf("  ");
    printf("%s\n", t->v);

    printTree(t->l, d + 1);
    printTree(t->r, d + 1);
}

void yyerror(const char *s) { printf("Invalid\n"); exit(0); }
int yylex(void);

%}

%union {
    char *s;
    struct node *n;
}

%token <s> ID
%type <n> E
%left '+' '-'
%left '*' '/'

%%

S: E            { printf("AST:\n"); printTree($1, 0); }
 ;

E: E '+' E      { $$ = mknode("+", $1, $3); }
 | E '-' E      { $$ = mknode("-", $1, $3); }
 | E '*' E      { $$ = mknode("*", $1, $3); }
 | E '/' E      { $$ = mknode("/", $1, $3); }
 | '(' E ')'    { $$ = $2; }
 | ID           { $$ = mknode($1, NULL, NULL); }
 ;

%%

int main(void) {
    printf("Enter expression: ");
    fflush(stdout);
    yyparse();
    return 0;
}

/*
==================================================
SAMPLE INPUT & OUTPUT:
==================================================
Enter expression: a+b*c
AST:
+
  a
  *
    b
    c

==================================================
DEBIAN / UBUNTU COMMANDS TO RUN:
==================================================
# 1. Install prerequisites (if not already installed):
# sudo apt-get update && sudo apt-get install -y bison flex gcc

# 2. Compile and execute:
bison -dy ast.y
flex ast.l
gcc y.tab.c lex.yy.c -o ast
./ast
==================================================
*/
