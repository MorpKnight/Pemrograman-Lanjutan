#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// inisialisasi data dengan struct
typedef struct BIODATA{
    char name[100];
    int npm;
    float IPK;
} biodata;

// input data untuk dimasukan ke struct
void input_data(biodata *a, int i){
    printf("Nama pelajar ke-%d: ", i+1);
    scanf("\n");
    scanf("%[^\n]s", (a+i)->name);

    printf("NPM pelajar ke-%d: ", i+1);
    scanf("%d", &(a+i)->npm);

    printf("IPK pelajar ke-%d: ", i+1);
    scanf("%f", &(a+i)->IPK);
}

// menggunakan bubble sort sebagai sorting untuk nama
void sort_by_name(biodata *a, int n){
    biodata temp;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(strcmp((a+j)->name, (a+j+1)->name) > 0){
                temp = a[j];
                a[j] =  a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// menggunakan bubble sort sebagai sorting untuk ipk
void sort_by_ipk(biodata *a, int n){
    biodata temp;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(a[j].IPK < a[j+1].IPK){
                temp = a[j];
                a[j] =  a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// menggunakan bubble sort sebagai sorting untuk npm
void sort_by_npm(biodata *a, int n){
    biodata temp;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(a[j].npm > a[j+1].npm){
                temp = a[j];
                a[j] =  a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int i, n, mode, break_mode;
    char mode_choosen[10];
    printf("Masukan jumlah pelajar (3..10): ");
    // program akan loop, sampai input yang diminta sesuai dengan batasan yang diberikan
    while(1){
        scanf("%d", &n);
        if(n <= 10 && n >= 3){
            break;
        } else {
            printf("Masukan ulang data(3..10): ");
        }
    }

    // inisialisasi struct biodata
    biodata data[n];
    for(i = 0; i < n; i++){
        input_data(data, i);
        printf("\n");
    }
    menu:
    // input mode pengurutan yang akan ditampilkan/digunakan
        printf("Urut berdasarkan: \n1. Nama\n2. NPM\n3. IPK\n4. Exit\n\nPilihan: ");
        scanf("%d", &mode);
        switch(mode){
            case 1:
                strcpy(mode_choosen, "nama");
                sort_by_name(data, n);
                break;
            case 2:
                strcpy(mode_choosen, "NPM");
                sort_by_npm(data, n);
                break;
            case 3:
                strcpy(mode_choosen, "IPK");
                sort_by_ipk(data, n);
                break;
            case 4:
                printf("Keluar dari program...");
                exit(0);
                break;
            default:
                printf("Masukan ulang (1..4): \n");
                // apabila diluar 1..4, maka akan menggunakan goto untuk kembali ke section menu
                goto menu;
            }
    
    // printout hasil sortingan
    printf("Pengurutan berdasarkan %s:\n", mode_choosen);
    for(i = 0; i < n; i++){
        printf("%s ||NPM: %2d ||IPK: %2.2f\n", data[i].name, data[i].npm, data[i].IPK);
    }
    printf("\n");
    // balik ke section menu
    goto menu;

    return 0;
}