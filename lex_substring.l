
%{
#include <stdio.h>
%}

%%
.*[Aa][Mm][Ii][Tt].*  { printf("Rejected!\n"); }
.*                    { printf("Accepted!\n"); }
%%

int main()
{
    printf("Enter string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

/*
DEBIAN LINUX COMMANDS:

gedit nam.l
flex nam.l
gcc lex.yy.c -o nam
./nam

SAMPLE INPUT 1:
Hello AMIT

OUTPUT:
Enter string: Hello AMIT
Rejected!

SAMPLE INPUT 2:
Hello World

OUTPUT:
Enter string: Hello World
Accepted!

Press Ctrl + D to terminate input.
*/
