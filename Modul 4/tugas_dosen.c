#include <stdio.h>

int linear_sort(int arr[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int divide_array(int arr[], int n, int n_divide){
    int i, j, k;
    int arr_divide[n_divide][n/n_divide];
    k = 0;
    for(i=0; i<n_divide; i++){
        if(n % n_divide != 0 && i == n_divide-1){
            for(j=0; j<n/n_divide+1; j++){
                arr_divide[i][j] = arr[k];
                k++;
            }
        } else {
            for(j=0; j<n/n_divide; j++){
                arr_divide[i][j] = arr[k];
                k++;
            }
        }
    }
}

int main(){
    int arr[] = {100, 56, 5, 6, 102, 58, 101, 57, 7, 103};
    int i, j, n, n_divide;
    n = sizeof(arr)/sizeof(arr[0]);
    linear_sort(arr, n);

    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("N_divide: ");
    scanf("%d", &n_divide);
    
    // divide array to arr[3][x]
    int arr_divide[n_divide][n/n_divide];
    divide_array(arr, n, n_divide);

    // print array
    for(i=0; i<n_divide; i++){
        for(j=0; j<n/n_divide; j++){
            printf("%d ", arr_divide[i][j]);
        }
        printf("\n");
    }

    return 0;
}