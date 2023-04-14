#include <stdio.h>

// soal no 3 total array
int totalArray(int arr[], int n){
    int i, total = 0;
    for(i = 0; i < n; i++){
        total += arr[i];
    }

    return total;
}

// soal no 4 perbandingan
void arrayCompare(int a, int b){
    if(a > b){
        printf("Jumlah B > Jumlah C\n");
    } else if(a < b){
        printf("Jumlah B < Jumlah C\n");
    } else {
        printf("Jumlah B = Jumlah C\n");
    }
}

// soal no 5 nilai maksimal / terbesar masing masing
int maxOf(int arr[], int n){
    int i, max = 0;
    for(i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

// soal no 6 urutkan ascending
void sortArray(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}