#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

typedef struct Array{
    int data;
    struct Array *next;
} Array;

int getValidInteger(){
    int input;
    char buff[256], c;

    while (1) {
        if (fgets(buff, sizeof(buff), stdin) != NULL) {
            if (sscanf(buff, " %d", &input) == 1) {
                return input;
            } else {
                printf("Salah. Masukkan sebuah integer lalu tekan enter:\n");
            }

        } else {
            printf("Error membaca input, silahkan masukkan ulang: ");
            clearerr(stdin);
        }
    }
}

void printArray(Array *head){
    Array *temp = head;

    printf("\nHasil akhir B: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertData(Array **head, int data){
    Array *temp = (Array*)malloc(sizeof(Array));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

int main(){
    Array *B = NULL;
    int A[10], i, count;
    srand(time(NULL));
    count = 0;

    printf("Selamat datang. Program ini dibuat oleh Giovan Christoffel Sihombing (NPM: 2206816084)\n");
    for(i = 0; i < 10; i++){
        printf("Masukkan sebuah integer ke-%d lalu tekan Enter:\n", i+1);
        A[i] = getValidInteger();
    }
    printf("3 thread akan memindahkan isi A ke B:\n");

    #pragma omp parallel num_threads(3)
    {
        int threadID = omp_get_thread_num();
        #pragma omp critical
        {   
            for(i = 0; i < 3; i++){
                int random = (rand() % 10) + 1;
                int val = A[random-1];
                
                printf("Thread %d memindahkan isi A[%d]=%d ke B[%d]\n", threadID, random, val, count);
                insertData(&B, val);
                count++;
            }
        }
    }

    printArray(B);

    return 0;
}