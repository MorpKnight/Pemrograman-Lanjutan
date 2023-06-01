#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode{
    char nama[50], penyakit[50];
    int nomorAntrian;
    struct QueueNode *nextPtr;
} AntrianPasien;

typedef AntrianPasien *AntrianPtr;

// ornamen
void red () {
  printf("\033[1;31m");
}

void white(){
    printf("\033[0m");
}

void green(){
    printf("\033[0;32m");
}

// daftar pasien kala dipanggil
void daftarPasien(AntrianPtr *headPtr, AntrianPtr *tailPtr, int nomorAntrian){
    AntrianPtr newPtr;
    char name[50];
    newPtr = malloc(sizeof(AntrianPasien));

    if(newPtr != NULL){
        printf("\nMasukan nama pasien: ");
        scanf("\n");
        scanf("%[^\n]s", newPtr->nama);
        printf("Masukan keluhan/penyakit yang diderita: ");
        scanf("\n");
        scanf("%[^\n]s", newPtr->penyakit);
        newPtr->nomorAntrian = nomorAntrian;
        newPtr->nextPtr = NULL;

        if(*headPtr == NULL){
            *headPtr = newPtr;
        } else {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    } else {
        printf("Tidak dapat memasukan data pasien!\n");
    }
}

// print daftar antrian
void printQueue(AntrianPtr current){
    red();
    printf("\nAntrian pasien:\n");
    white();
    while(current != NULL){
        printf("%d. %s\n", current->nomorAntrian, current->nama);
        printf("Penyakit: %s\n\n", current->penyakit);
        current = current->nextPtr;
    }
}

// panggil pasien kala siap
void panggilPasien(AntrianPtr *headPtr, AntrianPtr *tailPtr){
    AntrianPtr tempPtr;

    if(*headPtr == NULL){
        printf("\nTidak ada antrian!\n");
    } else {
        int deVal;
        tempPtr = *headPtr;
        green();
        printf("\nPasien yang menemui dokter:\n");
        white();
        printf("Nama: %s\nNomor antrian: %d\nPenyakit/keluhan: %s\n", tempPtr->nama, tempPtr->nomorAntrian, tempPtr->penyakit);
        *headPtr = (*headPtr)->nextPtr;

        if(*headPtr == NULL){
            *tailPtr = NULL;
        }

        free(tempPtr);
    }
}

int main(){
    AntrianPtr headPtr, tailPtr;
    headPtr = NULL;
    tailPtr = NULL;

    int choice, nomorAntrian;
    nomorAntrian = 1;

    do {
        printf("Silakan pilih menu!\n1. Pasien datang\n2. Panggil pasien\n3. Tutup klinik\nMasukan pilihan: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                daftarPasien(&headPtr, &tailPtr, nomorAntrian);
                printQueue(headPtr);
                nomorAntrian++;
                break;
            case 2:
                if(headPtr != NULL){
                    panggilPasien(&headPtr, &tailPtr);
                    printQueue(headPtr);
                } else {
                    red();
                    printf("\nTidak ada antrian!\n\n");
                    white();
                }
                break;
            case 3:
                if(headPtr == NULL){
                    printf("\nKlinik dah tutup, cari tempat lain!\n");
                } else {
                    printf("\nKlinik tutup mendadak, pasien yang tersisa cari tempat lain!\n");
                }
                break;
            default:
                printf("Opsi tidak ditemukan, harap masukan opsi yang sesuai!\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}