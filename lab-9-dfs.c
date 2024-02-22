#include <stdio.h>
#include <stdlib.h>

#define size 7
int pos = -1;
int stack[size];

void push(int a);
int pop();
void display();
void dfs(int graph[][7]);

int main(){
    int adj_matrix[7][7] = {
        {0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
    };
    dfs(adj_matrix);
    for(int i = 0; i < 7; i++) stack[i] = NULL;
}

void dfs(int graph[][7]){
    int visited[7];
    for (int i = 0; i < 7; i++) visited[i] = 0;
    push(0); visited[0] = 1; printf("0 ");
    printf("%d ", pos);
    return;
    // display();
    while(pos != -1){
        for(int i = 0; i < 7; i++){
            if(graph[stack[pos]][i] == 1 && visited[i] != 1){
                push(i);
                display();
                break;
                visited[i] = 1; printf("%d ", i);
                break;
            }
            pop();
        }
    }

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
    return stack[pos--];
}

void display(){
    for(int i = 0; i < size; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}