#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 7

void push(int a);
int pop();
void display();
void bfs(int graph[][size]);

int fpos = -1, rpos = -1;
int queue[size];

int main(){
   int adj_matrix[size][size] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
    };
    for(int i = 0; i < size; i++) queue[i] = NULL;
    // display();
    bfs(adj_matrix);
    return 0;

}

void bfs(int graph[][size]){
    int visited[size];
    for(int i = 0; i < size; i++) visited[i] = 0;
    push(0); visited[0]= 1;
    while (fpos != size){
        for(int i = 0; i < size; i++){
            if(graph[queue[fpos]][i] == 1 && visited[i] != 1){
                push(i);
                visited[i] = 1;
                // break;
            }
        }
        printf("%d ", pop());
        // printf("%d\n", new_node);
    }
}

void push(int a){
    if (fpos == -1 && rpos == -1){
        queue[++rpos] = a;
        fpos++;
        return;
    }
    else if (rpos == size-1){
        printf("Queue overflow condition\n");
        return;
    }
    else{
        queue[++rpos] = a;
        return;
    }
}

int pop(){
    if (fpos == -1){
        printf("Queue Underflow condition\n");
    }
    int n = queue[fpos];
    queue[fpos] = (int) NULL;
    fpos++;
    return n;
}

void display(){
    printf("Queue: ");
    for(int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
