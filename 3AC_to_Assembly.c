#include <stdio.h>
#include <string.h>

int main(){
    
    char code[10][30],op[4];
    int i=0;
    
    printf("Enter IC (exit to end): \n");
    
    do{
        
        scanf("%30s",code[i]);        
        
    }while(strcmp(code[i++],"exit")!=0);
    
    
    for(int i=0;strcmp(code[i],"exit")!=0;i++){
        
        switch(code[i][3]){
            
            case '+':strcpy(op,"ADD");break;
            case '-':strcpy(op,"SUB");break;
            case '*':strcpy(op,"MUL");break;
            case '/':strcpy(op,"DIV");break;
            default:continue;
            
        }
        
        printf("MOV R%d,%c\n",i,code[i][2]);
        printf("%s R%d,%c\n",op,i,code[i][4]);
        printf("MOV %c,R%d\n",code[i][0],i);
    }
    return 0;
}
