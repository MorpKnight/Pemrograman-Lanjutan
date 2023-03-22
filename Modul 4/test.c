#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int *arr, int size){
    int i;
    printf("[");
    for(i=0 ; i<size ; i++){
        printf("%-2d, ", arr[i]);
    }
    printf("\b\b]");
}

void swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void arrCopy(int arr1[], int arr2[], int size){
    int i;
    for(i=0; i<size ; i++){
        arr1[i]=arr2[i];
    }
}

int selectionSort(int arraySize, int **arr) {
    int swapAmount = 0;
    for(int i = 0; i < arraySize; i++) {
        int min = i;
        for(int j = i + 1; j < arraySize; j++) {
            if(arr[swapAmount][min] > arr[swapAmount][j]) {
                min = j;
            }
        }
        if(i != min) {
            arr[swapAmount][arraySize] = i;
            arr[swapAmount][arraySize + 1] = min;
            swapAmount++;
            if(swapAmount <= 2) {
                arrCopy(arr[swapAmount], arr[swapAmount - 1], arraySize);
                swap(arr[swapAmount], i, min);
            } else {
                break;
            }
        }
    }

    return swapAmount;
}

int printSteps(int swapAmount, int **arr, int arraySize) {
    if(swapAmount <= 2){
        for(int i = swapAmount; i >= 0; i--){
            printArray(arr[i], arraySize);
            if(i != 0){
                printf(" -> ");
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int i, j, swapAmount=0, arraySize=0, min, returnal;

    while(arraySize<1){
        printf("\nSize of array:");
        scanf("%d", &arraySize);
    }

    int **arr=(int**)malloc(arraySize-1*sizeof(int*));
    for(i=0 ; i<arraySize-1; i++){
        arr[i]=(int*)malloc(arraySize+2*sizeof(int));
    }

    for(i=0 ; i<arraySize ; i++){
        scanf("%d", &arr[0][i]);
    }
    printf("Input: ");
    printArray(arr[0], arraySize);
    printf("\n");

    swapAmount = selectionSort(arraySize, arr);
    printf("Output: ");
    printArray(arr[1], arraySize);
    printf("\n");

    printf("Swap Amount: %d\n", swapAmount);

    printf("Steps: ");
    returnal = printSteps(swapAmount, arr, arraySize);
    if (returnal == 0){
        printf("Not possible to print steps\n");
    }

    return 0;
}