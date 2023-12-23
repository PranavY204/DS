#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define size 20

void push(char a);
char pop();
void display();
char* postfix(char* exp);
char* prefix(char* exp);
bool character(char c);
bool lower_precedence(char op1, char op2);
bool isEmpty();


int pos = -1;
char stack[size];
int n;

int main(){

    printf("Enter size of expression in terms of characters: ");
    scanf("%d", &n);
    fflush(stdin);
    char* expr = (char*) malloc(size*sizeof(char));
    printf("Enter infix expression: ");
    scanf("%[^\n]s", expr);
    char* postfixexp = postfix(expr);
    printf("Postfix expression: %s\n", postfixexp);
    char* prefixexp = prefix(expr);
    printf("Prefix expression: %s", prefixexp);

    return 0;
}

bool isEmpty(){
    return pos == -1;
}

void push(char a){
    if (pos == 9){
        printf("Stack Overflow condition");
        return;
    }
    stack[++pos] = a;
}

char pop(){
    if (pos == -1){
        printf("Stack Underflow condition");
        return (char) NULL;
    }
    
    char return_value = stack[pos];
    stack[pos] = (char) NULL;
    pos--;
    return return_value;
}

void display(){
    printf("Stack: ");
    for(int i = 0; i < size; i++){
        printf("%c ", stack[i]);
    }
    printf("\n");
}

bool character(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool lower_precedence(char op1, char op2){
    if (op1 == op2 && op2 == '^') return false;
    char op_order[] = {'^', '/', '*', '+', '-'};
    int o1, o2;
    for(int i = 0; i < 5; i++){
        if (op_order[i] == op1) o1 = i;
        if (op_order[i] == op2) o2 = i;
    }
   
    return o1 <= o2;

}

char* postfix(char* exp){
    char* return_exp = (char*) malloc((size+3)*sizeof(char));
    int current = 0;
    for(int i = 0; i < n; i++){
        
        if (character(exp[i])){
            return_exp[current++] = exp[i];  
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
            if (isEmpty()) push(exp[i]); 
                
            else if(lower_precedence(stack[pos], exp[i])){
                while(lower_precedence(stack[pos], exp[i]) && !isEmpty()){
                    if (stack[pos] != '(') return_exp[current++] = pop();
                    else{
                        pos--;
                        break;
                    }
                }
                push(exp[i]);
            }
            else push(exp[i]);
        }
        else if(exp[i] == '('){
            push('(');
        }
        else if(exp[i] == ')'){
            while(stack[pos] != '(' && !isEmpty()){
                return_exp[current++] = pop();  
            }
        }
       
        
    }

    while(!isEmpty()){
        if (stack[pos] != '(') return_exp[current++] = pop();
        else pos--;
    } 
   
    return return_exp;
    
}

char* prefix(char* exp){
    char* buffer = malloc(size*sizeof(char));
    for(int i = n-1; i >= 0; i--){
        buffer[n-i-1] = exp[i];
        if (buffer[n-i-1] == '(') buffer[n-i-1] = ')';
        else if (buffer[n-i-1] == ')') buffer[n-i-1] = '(';
    } 

    printf("Reversed String: %s\n", buffer);
    char* return_exp = malloc(size*sizeof(char));
    int current = 0;
    for(int i = 0; i < n; i++){
        
        if (character(buffer[i])){
            return_exp[current++] = buffer[i];  
        }
        else if(buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '^'){
            if (isEmpty()) push(buffer[i]); 
                
            else if(lower_precedence(stack[pos], buffer[i])){
                while(lower_precedence(stack[pos], buffer[i]) && !isEmpty()){
                    if (stack[pos] != '(') return_exp[current++] = pop();
                    else{
                        pos--;
                        break;
                    }
                }
                push(buffer[i]);
            }
            else push(buffer[i]);
        }
        else if(buffer[i] == '('){
            push('(');
        }
        else if(buffer[i] == ')'){
            while(stack[pos] != '(' && !isEmpty()){
                return_exp[current++] = pop();  
            }
        }
       
        
    }

   

    while(!isEmpty()){
        if (stack[pos] != '(') return_exp[current++] = pop();
        else pos--;
    } 

    char* final = (char*) malloc(size*sizeof(char));
    for(int i = 0; i < strlen(return_exp); i++)
        final[i] = return_exp[strlen(return_exp)-i-1];

    return final;
}

