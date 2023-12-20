#include <stdio.h>
#include <string.h>

struct User{
    char username[20];
    int balance;
} typedef user;

void deposit(int dep, user *user){
    user->balance += dep;
    printf("Current Balance: %d\n", user->balance);
}

void withdraw(int dep, user *user){
    user->balance -= dep;
    printf("Current Balance: %d\n", user->balance);
}

void balance(user *user){
     printf("Current Balance: %d\n", user->balance);
}
int main(){

    // 1 - bank account creation
    user user = {"Somebody", 1000};
    deposit(100, &user);
    withdraw(100, &user);
    balance(&user);

    // 2 - Sorting strings lexicogaphically
    int size = 4;
    char arr[4][10] = {"Pranav", "Abhinav", "Pratham", "pranav"};
    for(int i = 0; i < size - 1; i++){
        for(int j = i+1; j < size; j++){
            if (strcmp(arr[i], arr[j]) > 0){
                char buffer[10];
                strcpy(buffer, arr[j]);
                strcpy(arr[j], arr[i]);
                strcpy(arr[i], buffer);
            }
        }
    }
    printf("Sorted array: ");
    for(int i = 0; i < size; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");

    // 3 - element present in a 2-D array
    int ls1[3][5] = {{1, 3, 8, 9, 7}, {2, 4, 6, 10, 11}, {-5, 20, 13, 17, 5}};
    int row = 3, col = 5;
    int element;
    printf("Enter a key to be searched: ");
    scanf("%d", &element);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (ls1[i][j] == element){
                printf("Element found at index [%d][%d]", i, j);
            }
        }
    }
    printf("\n");

    // 4 - Searching for substring
    char string1[] = "Something";
    char string2[] = "Some";
    int n1 = strlen(string1), n2 = strlen(string2);
    for(int i = 0; i < n1-n2; i++){
        _Bool found = 0;
        for (int j = 0; j < n2; j++){
            if (string1[i+j] == string2[j]){
                found = 1;
            } else{
                found = 0;
            }
        }
        if (found){
            printf("Subset from (%d, %d)", i, i+n2-1);
            break;
        }
    }
    printf("\n");


    // 5 - Last occurence of a number
    int s = 10;
    int ls2[] = {1, 3, 5, 5, 3, 2, 1, 9, 8, 8};
    int elem;
    printf("Enter element to be searched: ");
    scanf("%d", &elem);
    for(int i = s-1; i >= 0; i--){
        if (ls2[i] == elem){
            printf("last occurrence of the number is at index %d", i);
            break;
        }
    }
    printf("\n");

    // 6 - linear search
    int n = 7;
    int ls3[] = {9, 1, 3, 4, 5, 7, 6};
    int e;
    printf("key to be searched: ");
    scanf("%d", &e);
    for(int i = 0; i < n; i++){
        if (ls3[i] == e) 
            printf("Key at index %d\n", i);
    }
    printf("\n");

    // 7 - binary search on sorted array
    int ls[10] = {-5, 1, 3, 4 , 9, 32, 10001};
    int key; 
    int l = 0, h = 9, mid;
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    while(l <= h){
        mid = (l+h)/2;
        if (ls[mid] > key){
            h = mid-1;
        }
        else if (ls[mid] < key){
            l = mid+1;
        }
        else if (ls[mid] == key){
            printf("Element found at index %d", mid);
            break;
        }
    }
    printf("\n");

    //8 - max and min in a list
    int ls4[10] = {-5, 1, 3, 4 , 9, 32, 10001};
    int max = ls4[0], min = ls4[0];
    for(int i = 0; i < 10; i++){
        if (ls4[i] > max){
            max = ls[i];
        }
        else if (ls4[i] < min){
            min = ls[i];
        }
    }
    printf("Max in list = %d; Min in list = %d", max, min);

    return 0;
}
