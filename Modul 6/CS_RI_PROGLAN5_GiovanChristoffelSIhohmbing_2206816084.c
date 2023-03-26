#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef struct database{
	char name[100];
    char initial[50];
} Name;

void sortName(Name *Data, int count) {
    Name temporary;
    char temp;
    // Sort names in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(Data[i].name, Data[j].name) > 0) {
                // Swap names
                temporary = Data[i];
                Data[i] = Data[j];
                Data[j] = temporary;
            }
        }
    }

    // for(int i = 0; i < count; i++){
    //     for(int j = 0; j < strlen(Data[i].name); j++){
    //         if(j == 0){
    //             temp = Data[i].name[j];
    //             strncat(Data[i].initial, &temp, 1);
    //         }
    //         if(Data[i].name[j] == ' '){
    //             temp = Data[i].name[j+1];
    //             strncat(Data[i].initial, &temp, 1);
    //         }
    //     }
    // }
}

void create_initial(Name *Data, int count){
    char temp;
    for(int i = 0; i < count; i++){
        for(int j = 0; j < strlen(Data[i].name); j++){
            if(j == 0){
                temp = Data[i].name[j];
                if(islower(temp)){
                    temp = toupper(temp);
                }
                strncat(Data[i].initial, &temp, 1);
            }
            if(Data[i].name[j] == ' '){
                temp = Data[i].name[j+1];
                if(islower(temp)){
                    temp = toupper(temp);
                }
                strncat(Data[i].initial, &temp, 1);
            }
        }
    }
}

void printtoFileSorted(Name *Data, int count){
    char temp[200];
    FILE *fp = fopen("daftar_pembeli_sorted.txt", "w");
    fprintf(fp, "NAMA\n");

    for(int i = 0; i < count; i++){
        fprintf(fp, "%s", Data[i].name);
    }

    fclose(fp);
}

void InputData(Name *Data, int count){
    char temp;
    count++;
    FILE *fp = fopen("daftar_pembeli.txt", "a");
    printf("Nama: ");
    scanf("\n");
    scanf("%[^\n]s", &Data[count].name);

    fprintf(fp, "%s\n", Data[count].name);
    fclose(fp);
}

void getNamebyInitial(Name *Data, int count){
    // get all possible name by initial
    char initial[50];
    printf("Masukan inisial: ");
    scanf("%s", &initial);
    for(int i = 0; i < count; i++){
        if(strcmp(Data[i].initial, initial) == 0){
            printf("%s", Data[i].name);
        }
    }
}

int main() {
    Name Data[100]; // assuming max count is 100
    int count = 0;
    int mode, input, i;
    char temp[200];
    FILE *fp = fopen("daftar_pembeli.txt", "r+");

    if(fp == NULL){
        printf("File tidak ditemukan");
        exit(1);
    }

    printf("Masukan jumlah Nama: ");
    scanf("%d", &input);

    fgets(temp, 200, fp);
    while(fgets(temp, 200, fp) != NULL){
        sscanf(temp, "%[^,]", Data[count].name);
        count++;
    }

    for(i = 0; i < input; i++){
        printf("Nama-%d : %s", i+1, Data[i].name);
    }
    create_initial(Data, count);

    printf("\n\nPROGRAM MENCARI INISIAL\n1. Input Data\n2. Cari Inisial\n3. Urutkan Data\nInput: ");
    scanf("%d", &mode);
    switch(mode){
        case 1:
            InputData(Data, count);
            count++;
            break;
        case 2:
            getNamebyInitial(Data, count);
            break;
        case 3:
            sortName(Data, input);
            printf("\nMemproses");
            for(int j = 0; j < 3; j++){
                Sleep(500);
                printf(".");
            }
            printtoFileSorted(Data, input);
            break;
        case 4:
            printf("Exiting");
            for(int k = 0; k < 3; k++){
                Sleep(500);
                printf(".");
            }
            exit(0);
        default:
            break;
    }
    return 0;
}
