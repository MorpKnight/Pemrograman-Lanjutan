#include <stdio.h>
#include <stdlib.h>

typedef struct DATA {
    char name[100];
    int age;
} ID;

int main(){
    int n, i, j, k;
    FILE *fp;
    printf("How much data to enter:");
    scanf("%d", &n);

    ID id[n];
    fp = fopen("database.txt", "r+");
    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    for(i = 0; i < n; i++){
        printf("Name: ");
        scanf("%s", id[i].name);
        printf("Age: ");
        scanf("%d", &id[i].age);
        fprintf(fp, "%s %d\n", id[i].name, id[i].age);
    }

    fclose(fp);

    return 0;
}