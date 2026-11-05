
#include <stdio.h>

int top = -1, i = 0;
char s[100], st[100];

void reduce()
{
    while(1)
    {
        if(top >= 0 && st[top] == 'i')
        {
            st[top] = 'E';
        }
        else if(top >= 2 && st[top] == ')' &&
                st[top-1] == 'E' && st[top-2] == '(')
        {
            top -= 2;
            st[top] = 'E';
        }
        else if(top >= 2 && st[top] == 'E' &&
                st[top-1] == '*' && st[top-2] == 'E')
        {
            top -= 2;
            st[top] = 'E';
        }
        else if(top >= 2 && st[top] == 'E' &&
                st[top-1] == '+' && st[top-2] == 'E' &&
                s[i] != '*')
        {
            top -= 2;
            st[top] = 'E';
        }
        else
        {
            break;
        }

        st[top+1] = '\0';
    }
}

int main()
{
    printf("Grammar: E -> (E) | E+E | E*E | id\n\n");

    printf("Enter expression: ");
    scanf("%99s", s);

    printf("\nStack\tInput\tAction\n");

    while(s[i])
    {
        if(s[i] == 'i' && s[i+1] == 'd')
        {
            st[++top] = 'i';
            i += 2;
        }
        else
        {
            st[++top] = s[i++];
        }

        st[top+1] = '\0';

        printf("%s\t%s\tShift\n", st, s+i);

        reduce();

        printf("%s\t%s\tReduce\n", st, s+i);
    }

    reduce();

    if(top == 0 && st[0] == 'E')
    {
        printf("\n\nString Accepted!");
    }
    else
    {
        printf("\n\nString Rejected!");
    }

    return 0;
}

/*
SAMPLE INPUT:
id+id

SAMPLE OUTPUT:

Grammar: E -> (E) | E+E | E*E | id

Enter expression: id+id

Stack   Input   Action
i       +id     Shift
E       +id     Reduce
E+      id      Shift
E+      id      Reduce
E+i             Shift
E               Reduce

String Accepted!
*/
