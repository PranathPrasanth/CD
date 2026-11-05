
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int i=0;
char s[100];

void E();
void T();
void F();

void match(char c)
{
    if(s[i]==c)
        i++;
    else
        exit(0);
}

void E()
{
    T();

    while(s[i]=='+' || s[i]=='-')
    {
        match(s[i]);
        T();
    }
}

void T()
{
    F();

    while(s[i]=='*' || s[i]=='/')
    {
        match(s[i]);
        F();
    }
}

void F()
{
    if(s[i]=='(')
    {
        match('(');
        E();
        match(')');
    }
    else if(isalnum((unsigned char)s[i]))
    {
        while(isalnum((unsigned char)s[i]))
            i++;
    }
    else
        exit(0);
}

int main()
{
    printf("Grammar:\n");
    printf("E -> E+T | E-T | T\n");
    printf("T -> T*F | T/F | F\n");
    printf("F -> (E) | id\n");

    printf("Enter expression ($ at end): ");
    scanf("%99s",s);

    E();

    if(s[i]=='$')
        printf("String Parsed!\n");
    else
        printf("Invalid String!\n");

    return 0;
}

/* Sample Input:
   a+b*c$

   Sample Output:
   Grammar:
   E -> E+T | E-T | T
   T -> T*F | T/F | F
   F -> (E) | id
   Enter expression ($ at end): a+b*c$
   String Parsed!
*/
