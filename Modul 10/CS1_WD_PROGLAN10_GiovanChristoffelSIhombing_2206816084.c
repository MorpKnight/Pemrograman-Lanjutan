#include <stdio.h>

int main(){
    int n, i, j, k, temp;
    k = 0;

    printf("Masukan n: ");
    scanf("%d", &n);
    
    int arr[(2*n)+2], dup[n], nondup[2];
    printf("Masukan elemen elemen array: ");
    for(i = 0; i < (2*n)+2; i++){
        scanf("%d", &arr[i]);
    }

    // sorting
    for(i = 0; i < (2*n)+2; i++){
        for(j = 0; j < (2*n)+2 - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print duplikat
    printf("\n");
    for(i = 0; i < (2*n)+2; i++){
        if(arr[i] == arr[i+1]){
            i++;
        } else {
            nondup[k] = arr[i];
            printf("%d ", arr[i]);
        }
    }
    

    return 0;
}