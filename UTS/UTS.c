#include <stdio.h>
#include "UTS_HEADER.h"

int main(){
    int arr[10];
    int i, j, kel, totalArr1, totalArr2;

    printf("Array A (input): ");
    for(i = 0; i < 10; i++){
        do{
            scanf("%d", &arr[i]);
            if(arr[i] < 0){
                printf("Input harus positif!\n");
            }
        } while(arr[i] < 0);
    }

    // soal no 1, cetak hasil inputan
    printf("Array A: ");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    // soal no 2.a (kelipatan 4)
    j = 1;
    for(i = 0; i < 10; i++){
        if(arr[i] % 4 == 0){
            j++;
        }
    }
    kel = j;
    
    int keliaptan_4[j];
    int ganjil[10-j];

    j = 0;
    for(i = 0; i < 10; i++){
        if(arr[i] % 4 == 0){
            if(arr[i] == 0){
                continue;
            }

            keliaptan_4[j] = arr[i];
            j++;
        }
    }

    kel = j;

    printf("Array B (kelipatan 4): ");
    for(i = 0; i < j; i++){
        printf("%d ", keliaptan_4[i]);
    }
    printf("\n");

    // soal no 2.b (ganjil)
    j = 0;
    for(i = 0; i < 10; i++){
        if(arr[i] % 2 != 0){
            ganjil[j] = arr[i];
            j++;
        }
    }

    printf("Array C (ganjil): ");
    for(i = 0; i < j; i++){
        printf("%d ", ganjil[i]);
    }
    printf("\n");
    totalArr1 = totalArray(keliaptan_4, kel);
    totalArr2 = totalArray(ganjil, j);

    printf("Jumlah B: ");
    for(i = 0; i < kel; i++){
        if(i == kel-1){
            printf("%d = %d\n", keliaptan_4[i], totalArr1);
        } else {
            printf("%d + ", keliaptan_4[i]);
        }
    }

    printf("Jumlah C: ");
    for(i = 0; i < j; i++){
        if(i == j-1){
            printf("%d = %d\n", ganjil[i], totalArr2);
        } else {
            printf("%d + ", ganjil[i]);
        }
    }

    arrayCompare(totalArr1, totalArr2);
    printf("Elemen terbesar B: %d\n", maxOf(keliaptan_4, kel));
    printf("Elemen terbesar C: %d\n", maxOf(ganjil, j));
    sortArray(keliaptan_4, kel);
    sortArray(ganjil, j);

    printf("Array B (ascending): ");
    for(i = 0; i < kel; i++){
        printf("%d ", keliaptan_4[i]);
    }
    printf("\n");

    printf("Array C (ascending): ");
    for(i = 0; i < j; i++){
        printf("%d ", ganjil[i]);
    }
    printf("\n");

    return 0;
}