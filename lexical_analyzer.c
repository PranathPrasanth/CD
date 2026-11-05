#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    int ch, i;
    char word[100];

    char keywords[][10] = {
        "int", "float", "char", "double", "void",
        "if", "else", "while", "for", "do",
        "return", "break", "continue", "switch",
        "case", "default", "long", "short",
        "signed", "unsigned", "const", "static",
        "struct", "union", "enum", "typedef",
        "sizeof", "goto", "auto", "extern",
        "register", "volatile"
    };

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
            continue;

        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            word[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                if (i < 99)
                    word[i++] = ch;
            }

            word[i] = '\0';

            if (ch != EOF)
                ungetc(ch, fp);

            int k, found = 0;

            for (k = 0; k < 32; k++)
            {
                if (strcmp(word, keywords[k]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("Keyword : %s\n", word);
            else
                printf("Identifier : %s\n", word);
        }
        else if (isdigit(ch))
        {
            i = 0;
            word[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
            {
                if (i < 99)
                    word[i++] = ch;
            }

            if (ch == '.')
            {
                word[i++] = ch;

                while ((ch = fgetc(fp)) != EOF && isdigit(ch))
                {
                    if (i < 99)
                        word[i++] = ch;
                }
            }

            word[i] = '\0';

            if (ch != EOF)
                ungetc(ch, fp);

            printf("Number : %s\n", word);
        }
        else if (strchr("+-*/%=<>!&|^", ch) != NULL)
        {
            int next = fgetc(fp);

            if (next == '=' ||
                (next == ch && strchr("+-&|", ch) != NULL))
            {
                printf("Operator : %c%c\n", ch, next);
            }
            else
            {
                printf("Operator : %c\n", ch);

                if (next != EOF)
                    ungetc(next, fp);
            }
        }
        else
        {
            printf("Special Symbol : %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

/*
Sample Input (input.txt):

int main()
{
    int a = 10;
    float b = 20.5;
    a = a + b;
    return 0;
}

Sample Output:

Keyword : int
Identifier : main
Special Symbol : (
Special Symbol : )
Special Symbol : {
Keyword : int
Identifier : a
Operator : =
Number : 10
Special Symbol : ;
Keyword : float
Identifier : b
Operator : =
Number : 20.5
Special Symbol : ;
Identifier : a
Operator : =
Identifier : a
Operator : +
Identifier : b
Special Symbol : ;
Keyword : return
Number : 0
Special Symbol : ;
Special Symbol : }
*/
