#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
	char symbol;
	struct node *next;
} node;

node * START=NULL;

void push(char a){
    node temp=(node)malloc(sizeof(node));
    temp->symbol=a;
    temp->next=START;
    START=temp;
}

char pop(){
    if(START==NULL){
        return '!';
    }
    else{
        char val=START->symbol;
        node *temp=START;
        START=START->next;
        free(temp);
        return val;
    }
}
char peek(){
    if(START==NULL){
        return '!';
    }
    else{
        return START->symbol;
    }
}
int precedence(char a){
    char priority[]={'-','+','*','/','^'};
    int x=0;
    for(x=0;x<5;x++){
        if(a==priority[x]){
            return x+1;
        }  
    }
    return 0;
}

int main(){
    char str[100];

    printf("enter the expression you want to find the postfix of ");
    scanf("%s", str);
    int i=0;
    int length = strlen(str);

    for(i=0;i<length;i++){
        if(isalpha(str[i])){
            printf("%c", str[i]);
        }
        else{
            if(str[i]=='(')    push(str[i]);
            else if(str[i]==')'){
                while(peek()!='('){
                    printf("%c",pop());
                }
                pop();
                //printf("(%c)",pop());
            }
            else{
                if(precedence(peek())<=precedence(str[i])){
                    push(str[i]);
                }
                else{
                    while(precedence(str[i])>=precedence(peek())&&peek()!='!'&&peek()!='!'){
                        printf("%c",pop());
                    }
                    push(str[i]);
                }
            }
        }
    }
    while(peek()!='!'){
        printf("%c",pop());
    }
    return 0;
}
