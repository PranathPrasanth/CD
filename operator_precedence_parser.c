#include <stdio.h>

int top=-1,ip=0,expect=1;
char s[50],in[50];

int prec(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

int reduce(){
    if(top>=2 && s[top]=='E' && s[top-2]=='E'){
        top-=2;
        s[top]='E';
        return 1;
    }
    return 0;
}

int main(){

    printf("Enter expression (end with $): ");
    scanf("%49s",in);
    s[++top]='$';

    while(1){

        char b=in[ip];

        if(expect && b=='i'){
            s[++top]='E';
            ip++;
            expect=0;
        }
        else if(expect && b=='('){
            s[++top]='(';
            ip++;
        }
        else if(!expect && (b=='+' || b=='-' || b=='*' || b=='/')){
            int j=top;
            while(s[j]=='E') j--;

            if(s[j]=='(' || prec(s[j])<prec(b)){
                s[++top]=b;
                ip++;
                expect=1;
            }
            else if(!reduce()) break;
        }
        else if(!expect && b==')'){
            if(top>=1 && s[top]=='E' && s[top-1]=='('){
                top--;
                ip++;
            }
            else if(!reduce()) break;
        }
        else if(!expect && b=='$'){
            if(top==1 && s[top]=='E' && in[ip+1]=='\0'){
                printf("Accepted!");
                return 0;
            }
            if(!reduce()) break;
        }
        else break;
    }

    printf("Rejected!");
    return 0;
}

/*
Input:  i+i*i$
Output: Accepted!
*/
