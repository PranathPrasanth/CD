#include <stdio.h>
#include <ctype.h>

int main(){
    
    int n,i,j,change;
    char p[10][20],F[26][128]={0},L[26][128]={0};
    
    printf("Enter no. of productions: ");
    scanf("%d",&n);
    
    printf("Enter productions:(S->A , A->B, etc.) \n");
    
    for(i=0;i<n;i++){
        scanf("%s",p[i]);
    }
    
    do{
        change=0;
        
        for(i=0;i<n;i++){
            
            int a=p[i][0]-'A';
            char b=p[i][3];
            
            if(isupper(b)){
                for(j=0;j<128;j++){
                    if(F[b-'A'][j] && !F[a][j]){
                        F[a][j]=change=1;
                    }
                }
            }
            else if(!F[a][(int)b]){
                F[a][(int)b]=change=1;
            }
        }
    }while(change);
    
    L[p[0][0]-'A']['$']=1;
    
    do{
        change=0;
        
        for(i=0;i<n;i++){
            
            int a=p[i][0]-'A';
            char b=p[i][3];
            
            if(isupper(b)){
                for(j=0;j<128;j++){
                    if(L[a][j] && !L[b-'A'][j]){
                        L[b-'A'][j]=change=1;
                    }
                }    
            }
        }
    }while(change);
    
    for(i=0;i<26;i++){
        int found=0;
        for(j=0;j<n;j++){
            if(p[j][0]=='A'+i){
                found=1;
                break;
            }
        }
        
        if(found){
            printf("FIRST(%c) = {",'A'+i);
            
            for(j=0;j<128;j++){
                if(F[i][j]){
                    printf("%c",j);
                }
            }
            printf("}\n");
            
            printf("FOLLOW(%c) = {",'A'+i);
            
            for(j=0;j<128;j++){
                if(L[i][j]){
                    printf("%c",j);
                }
            }
            printf("}\n");
        }
    }return 0;
}
