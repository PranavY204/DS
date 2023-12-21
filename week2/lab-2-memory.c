#include <stdio.h>
#include <stdlib.h>

int size = 3;

int main(){

    int* arr = malloc(size*sizeof(int));
    int* arr2 = calloc(size, sizeof(int));
    printf("arr and arr2 can store %d integers", size);
    realloc(arr, 2*size*sizeof(int));
    printf("\nCan now store %d integers in arr and %d in arr2\n", 2*size, size);
    for(int i = 0; i < size; i++){
        arr2[i] = 1;
    }
    for(int i = 0; i < 2*size; i++){
        arr[i] = 0;
    }
    printf("arr: ");
    for(int i = 0; i < 2*size; i++){
        printf("%d ", arr[i]);
    }
    printf("\narr2: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr2[i]);
    }
    free(arr); free(arr2);
    return 0;
}
