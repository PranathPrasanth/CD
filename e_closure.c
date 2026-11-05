#include <stdio.h>
#define MAX 200

int n,e[MAX][MAX],v[MAX];

void closure(int s){

    v[s]=1;

    for(int i=0;i<n;i++){
        if(e[s][i] && !v[i]){
            closure(i);
        }
    }

}

int main(){

    int i,j,s;

    printf("Enter no. of states: ");
    scanf("%d",&n);

    printf("Enter epsilon-transition matrix (0 -> no epsilon transition, 1 -> epsilon transition): \n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&e[i][j]);
        }
    }

    printf("Epsilon closures: \n");

    for(s=0;s<n;s++){

        closure(s);

        printf("E(%d) = { ",s);

        for(i=0;i<n;i++){

            if(v[i]){
            printf("%d ",i);
            }
        }printf("}\n");

        for(i=0;i<n;i++){
            v[i]=0;
        }
    }

    return 0;
}

/*
Sample Input:

Enter no. of states: 4

Enter epsilon-transition matrix (0 -> no epsilon transition, 1 -> epsilon transition):
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0

Sample Output:

Epsilon closures:
E(0) = { 0 1 2 3 }
E(1) = { 1 2 3 }
E(2) = { 2 3 }
E(3) = { 3 }
*/
