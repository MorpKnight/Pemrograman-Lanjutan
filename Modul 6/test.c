#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *ptr;
    int i = 0, j = 0;
    char tmp[3][100], data[100][100];
    ptr = fopen("data.txt", "r");
    if(ptr != NULL){
        while(i < 100 && fscanf(ptr, "%100[^\n]s", tmp[0]) == 1 && fscanf(ptr, "%100[^\n]s", tmp[1]) == 1 && fscanf(ptr, "%100[^\n]s", tmp[2]) == 1){
            strcpy(data[i], tmp[2]);
            i++;
            strcpy(data[i], tmp[1]);
            i++;
            strcpy(data[i], tmp[0]);
            i++;
        }

        fclose(ptr);
    }

    ptr = fopen("data.csv", "w");
    if(ptr == NULL){
        printf("File tidak dapat dibuka");
        exit(1);
    }

    j = 0;

    while(j<100 && fprintf(ptr, "%s,%s,%s", strtok(data[j], "\n"), strtok(data[j+1], "\n"), strtok(data[j+2], "\n")) > 0){
        if(data[j+3][0] == '\0'){
            fclose(ptr);
            return 0;
        } else {
            j += 3;
        }
    }

    fclose(ptr);
    return 0;
}