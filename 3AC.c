
#include <stdio.h>
#include <string.h>

int main()
{
    char ex[50], op[50];
    char operand[50][10], temp[10];
    int i, j = 0, n = 0, t = 1;

    printf("Enter expression: ");
    scanf("%49s", ex);

    /* Separate operands and operators */
    for (i = 0; ex[i]; i++)
    {
        if (ex[i] == '+' || ex[i] == '-' ||
            ex[i] == '*' || ex[i] == '/')
        {
            op[n] = ex[i];
            n++;
        }
        else
        {
            operand[j][0] = ex[i];
            operand[j][1] = '\0';
            j++;
        }
    }

    /* Process * and / first */
    for (i = 0; i < n; i++)
    {
        if (op[i] == '*' || op[i] == '/')
        {
            sprintf(temp, "t%d", t++);

            printf("%s = %s %c %s\n",
                   temp, operand[i], op[i], operand[i+1]);

            strcpy(operand[i], temp);

            for (j = i; j < n-1; j++)
            {
                strcpy(operand[j+1], operand[j+2]);
                op[j] = op[j+1];
            }

            n--;
            i--;
        }
    }

    /* Process + and - */
    while (n > 0)
    {
        sprintf(temp, "t%d", t++);

        printf("%s = %s %c %s\n",
               temp, operand[0], op[0], operand[1]);

        strcpy(operand[0], temp);

        for (i = 0; i < n-1; i++)
        {
            strcpy(operand[i+1], operand[i+2]);
            op[i] = op[i+1];
        }

        n--;
    }

    printf("Result = %s\n", operand[0]);

    return 0;
}
