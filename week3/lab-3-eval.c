#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define size 20

void push(int a);
int pop();
void display();
bool isEmpty();
bool isOperator(char op);

int stack[size];
int pos = -1;
int n;

int main(){
    printf("Enter size of expression being given: ");
    scanf("%d", &n);
    char* exp = (char*) malloc(size*sizeof(char));
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    int n1, n2;
    for(int i = 0; i < n; i++){
        if(exp[i] >= '0' && exp[i] <= '9') push(exp[i]-'0');  
        else if(isOperator(exp[i])){
            n1 = pop(); n2 = pop();
            switch(exp[i]){
                case '+':
                    push(n2+n1);
                    break;
                case '-':
                    push(n2-n1);
                    break;
                case '*':
                    push(n2*n1);
                    break;
                case '/':
                    push(n2/n1);
                    break;
                case '^':
                    push(n2^n1);
                    break;
                default:
                    printf("Something is wrong");
            }
        }
    }
    printf("Final value: %d", pop());

    return 0;
    
}

bool isOperator(char op){
    char operators[] = {'^', '/', '*', '+', '-'};
    for (int i = 0; i < 5; i++){
        if (op == operators[i]) return true;
    }
    return false;
}

bool isEmpty(){
    return pos == -1;
}

void push(int a){
    if (pos == size-1){
        printf("Stack Overflow condition");
        return;
    }
    stack[++pos] = a;
}

int pop(){
    if (pos == -1){
        printf("Stack Underflow condition");
        return (int) NULL;
    }
    
    int return_value = stack[pos];
    stack[pos] = (int) NULL;
    pos--;
    return return_value;
}

void display(){
    printf("Stack: ");
    for(int i = 0; i < size; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}
