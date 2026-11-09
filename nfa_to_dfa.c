#include <stdio.h>

int n, m, t[20][2], q[1024], vis[1024], f = 0, r = 0;

void print_set(int s) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (s & (1 << i)) {
            printf("q%d", i);
        }
    }
    printf("}");
}

int main() {
    printf("Enter no. of states and transitions: ");
    scanf("%d %d", &n, &m);

    printf("enter transitions (eg : 0 0 1): \n");
    for (int i = 0; i < m; i++) {
        int u, c, v;
        scanf("%d %d %d", &u, &c, &v);
        t[u][c] |= (1 << v);
    }

    vis[1] = 1;
    q[r++] = 1;

    printf("\nEquivalent DFA : \n");
    while (f < r) {
        int s = q[f++];
        for (int c = 0; c < 2; c++) {
            int ns = 0;
            for (int i = 0; i < n; i++) {
                if (s & (1 << i)) {
                    ns |= t[i][c];
                }
            }

            print_set(s);
            printf("--(%d)--", c);
            print_set(ns);
            printf("\n");

            if (!vis[ns]) {
                vis[ns] = 1;
                q[r++] = ns;
            }
        }
    }
    return 0;
}

/*
Sample Input:
2 3
0 0 0
0 0 1
0 1 1

Sample Output:
Enter no. of states and transitions: 2 3
enter transitions (eg : 0 0 1): 
0 0 0
0 0 1
0 1 1

Equivalent DFA : 
{q0}--(0)--{q0q1}
{q0}--(1)--{q1}
{q0q1}--(0)--{q0q1}
{q0q1}--(1)--{q1}
{q1}--(0)--{}
{q1}--(1)--{}
{}--(0)--{}
{}--(1)--{}
*/
