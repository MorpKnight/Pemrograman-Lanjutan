#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

int main() {
    int n = 10;
    int arr[n];
    
    srand(time(NULL));
    
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Random array: ");
    printArray(arr, n);
    
    return 0;
}
