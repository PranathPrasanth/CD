#include <stdio.h>

int mark[20][20];

// Helper function to check if state pair (u, v) is marked distinguishable
int is_distinct(int u, int v) {
    if (u == v) return 0;
    return (u < v) ? mark[u][v] : mark[v][u];
}

int main() {
    int n, a[20], b[20], f[20], change;

    printf("Enter no of states: ");
    scanf("%d", &n);

    printf("\nEnter transitions on input 'a': \n");
    for (int i = 0; i < n; i++) {
        printf("state q%d on 'a': ", i);
        scanf("%d", &a[i]);
    }

    printf("\nEnter transition on input 'b': \n");
    for (int i = 0; i < n; i++) {
        printf("state q%d on input 'b': ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter final state(s): \n");
    for (int i = 0; i < n; i++) {
        printf("Is q%d a final state (0/1): ", i);
        scanf("%d", &f[i]);
    }

    // Step 1: Base Marking (Length 0 - Final vs Non-Final)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (f[i] != f[j]) {
                mark[i][j] = 1;
            }
        }
    }

    // Step 2: Inductive Propagation (Check transitions on 'a' and 'b')
    do {
        change = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!mark[i][j]) {
                    if (is_distinct(a[i], a[j]) || is_distinct(b[i], b[j])) {
                        mark[i][j] = 1;
                        change = 1;
                    }
                }
            }
        }
    } while (change);

    // Step 3: Print Equivalent States
    printf("\nDFA Minimization : \n");
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!mark[i][j]) {
                printf("q%d & q%d can be merged to form {q%d,q%d}\n", i, j, i, j);
                count++;
            }
        }
    }

    if (count == 0) {
        printf("\nNo DFA minimization. Already minimized!\n");
    } else {
        printf("\nNo of equivalent pairs found: %d\n", count);
    }

    return 0;
}

/*
============================= SAMPLE I/O =============================
Enter no of states: 4

Enter transitions on input 'a': 
state q0 on 'a': 1
state q1 on 'a': 1
state q2 on 'a': 1
state q3 on 'a': 1

Enter transition on input 'b': 
state q0 on input 'b': 2
state q1 on input 'b': 3
state q2 on input 'b': 2
state q3 on input 'b': 3

Enter final state(s): 
Is q0 a final state (0/1): 0
Is q1 a final state (0/1): 1
Is q2 a final state (0/1): 0
Is q3 a final state (0/1): 1

DFA Minimization : 
q0 & q2 can be merged to form {q0,q2}
q1 & q3 can be merged to form {q1,q3}

No of equivalent pairs found: 2
======================================================================
*/
