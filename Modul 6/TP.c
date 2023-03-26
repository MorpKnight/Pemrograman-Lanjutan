#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char temp[100];

    fp = fopen("data.txt", "r");

    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    while(fgets(temp, 100, fp) != NULL){
        printf("%s", temp);
    }

    fclose(fp);

    return 0;
}