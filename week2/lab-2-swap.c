#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a; *a = *b; *b = temp;
}

int main(){
    int a = 3, b = 4; 
    printf("a = %d; b = %d", a, b);
    swap(&a, &b);
    printf("\na = %d; b = %d", a, b);
    return 0;
}