#include <stdio.h>

int main() {
    int n, i, j, k, t, f_count;
    int e[20][20] = {0};
    int d[2][20][20] = {0};
    int final[20] = {0};
    char syms[] = {'a', 'b'};

    /* 1. Read States and Transitions */
    printf("enter no. of states: ");
    scanf("%d", &n);

    printf("enter no. of transitions: ");
    scanf("%d", &t);

    printf("Enter transitions (eg: 0 e 1, 1 a 2, 2 b 3,etc. ) : \n");
    for (i = 0; i < t; i++) {
        int u, v;
        char sym;
        scanf("%d %c %d", &u, &sym, &v);

        if (sym == 'e' || sym == 'E') {
            e[u][v] = 1;
        } else if (sym == 'a') {
            d[0][u][v] = 1;
        } else if (sym == 'b') {
            d[1][u][v] = 1;
        }
    }

    /* 2. Read Final States */
    printf("Enter no. of final states: ");
    scanf("%d", &f_count);

    printf("Enter final state(s) : \n");
    for (i = 0; i < f_count; i++) {
        int f;
        scanf("%d", &f);
        final[f] = 1;
    }

    /* 3. Compute Epsilon Closures using Warshall's Algorithm */
    for (i = 0; i < n; i++) {
        e[i][i] = 1;
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (e[i][k] && e[k][j]) {
                    e[i][j] = 1;
                }
            }
        }
    }

    /* 4. Compute New Transitions: delta'(i, sym) = e_close(delta(e_close(i), sym)) */
    printf("\nTransitions of NFA without E: \n");
    for (int s = 0; s < 2; s++) {
        for (i = 0; i < n; i++) {
            int res[20] = {0};

            for (int q = 0; q < n; q++) {
                for (int r = 0; r < n; r++) {
                    for (int w = 0; w < n; w++) {
                        if (e[i][q] && d[s][q][r] && e[r][w]) {
                            res[w] = 1;
                        }
                    }
                }
            }

            printf("d'(q%d,%c) = {", i, syms[s]);
            for (k = 0; k < n; k++) {
                if (res[k]) {
                    printf("%d", k);
                }
            }
            printf("}\n");
        }
    }

    /* 5. Compute New Final States */
    printf("\nNew Final States: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (e[i][j] && final[j]) {
                printf("%d", i);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}

/*
=====================================================
SAMPLE INPUT & OUTPUT
=====================================================
--- Input ---
enter no. of states: 3
enter no. of transitions: 3
Enter transitions (eg: 0 e 1, 1 a 2, 2 b 3,etc. ) : 
0 e 1
1 a 2
2 b 2
Enter no. of final states: 1
Enter final state(s) : 
2

--- Output ---
Transitions of NFA without E: 
d'(q0,a) = {2}
d'(q1,a) = {2}
d'(q2,a) = {}
d'(q0,b) = {}
d'(q1,b) = {}
d'(q2,b) = {2}

New Final States: 
2
=====================================================
*/
