#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr){
    int i, j, indexMin, temp;
    for(i = 0; i < 15-1; i++){
        indexMin = i;
        for(j = i+1; j < 15; j++){
            if(arr[j] < arr[indexMin]){
                temp = arr[j];
                arr[j] = arr[indexMin];
                arr[indexMin] = temp;
            }
        }
    }
}

int binary_search_recursive(int *arr, int x, int low, int high){
    int mid;
    if(high >= low){
        mid = low + (high - low)/2;

        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
            return binary_search_recursive(arr, x, low, mid-1);
        }
        return binary_search_recursive(arr, x, mid+1, high);
    }

    return -1;
}

int binary_search(int *arr, int x, int low, int high){
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] < x){
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int i, j, requested_number, result, n, arr[15];
    n = sizeof(arr)/sizeof(arr[0]);
    for(i = 0; i < 15; i++){
        arr[i] = rand()%100;
    }
    printf("Array: ");
    for(i = 0; i < 15; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr);

    printf("Masukan angka: ");
    scanf("%d", &requested_number);

    result = binary_search_recursive(arr, requested_number, 0, n-1);
    if(result == -1){
        printf("Takde");
    } else {
        printf("ade");
    }

    return 0;
}