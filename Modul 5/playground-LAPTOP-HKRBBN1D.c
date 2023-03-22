#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void red_font() {
    printf("\033[1;31m");
}

void green_font() {
    printf("\033[0;32m");
}

void reset_font() {
    printf("\033[0m");
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int median(int arr[], int size) {
    if (size % 2 == 0) {
        return (arr[size / 2] + arr[(size / 2) + 1]) / 2;
    } else {
        return arr[size / 2];
    }
}

int* findModus(int arr[], int size){
    int i;
    int *mostF = (int*)malloc(2*sizeof(int));
    int *current = (int*)malloc(2*sizeof(int));

    mostF[0]=99999;
    mostF[1]=-1;
    current[1]=0;

    for(i=0 ; i<size ; i++){
        current[0]=arr[i];
        current[1]=1;
        while(i+1<size && current[0]==arr[i+1]){
            current[1]++;
            i++;
        }
        if(current[1]>mostF[1]){
            mostF[0]=current[0];
            mostF[1]=current[1];
        }
    }
    return mostF;
}

// binary search
int search(int arr[], int size, int target){
    int high=size-1, low=0, mid=(high+low)/2;
    while(arr[mid]!=target){
        mid=(high+low)/2;
        if(low>high){
            return -1;
        }
        if(arr[mid]>target){
            high=mid-1;
        }
        if(arr[mid]<target){
            low=mid+1;
        }
    }
    return mid;
}

void printArray(int *arr, int size){
    int i;
    printf("[");
    for(i=0 ; i<size ; i++){
        printf("%-2d, ", arr[i]);
    }
    printf("\b\b]");
}

void random_number(int *arr, int size){
    srand(time(NULL));
    int i;
    for(i=0 ; i<size ; i++){
        arr[i]=rand()%100;
    }
}

int main(){
    int size=-1, target,i;
    clock_t start, end;
    double cpu_time_used;

    while(size<1){
        printf("\nN (len array) : ");
        scanf("%d", &size);
    }
    
    start = clock();
    int arr[size];
    
    random_number(arr,size);

    printf("Array         : ");
    red_font();
    printArray(arr, size);
    reset_font();

    quicksort(arr,0,size-1);
    printf("\nSorted array  : ");
    green_font();
    printArray(arr,size);
    reset_font();

    printf("\nMedian        : %d", median(arr,size));
    
    int *modus = findModus(arr,size);
    printf("\nModus         : %d\nFrekuensi     : %d", modus[0], modus[1]);
    end = clock();

    printf("\nTarget        : ");
    scanf("%d", &target);
    printf("Index         : %d", search(arr,size,target));

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime used     : %f", cpu_time_used);

    return 0;
}