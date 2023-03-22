#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DATA {
    char name[100];
    long long int NPM;
    char country[100];
} STUDENTS;

void readData(STUDENTS *data, int totalLine){
    FILE *fp;
    char temp[100];
    int i;

    fp = fopen("data.txt", "r");

    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    fgets(temp, 100, fp);
    for(i = 0; i < totalLine; i++){
        fgets(temp, 100, fp);
        strcpy(data[i].name, strtok(temp, ","));
        data[i].NPM = atoll(strtok(NULL, ","));
        strcpy(data[i].country, strtok(NULL, ","));
    }

    fclose(fp);
}

void printData(STUDENTS *data, int totalLine){
    int i;

    for(i = 0; i < totalLine; i++){
        printf("%s %lld %s", data[i].name, data[i].NPM, data[i].country);
    }
}

void appendData(STUDENTS data){
    FILE *fp;
    int i;

    fp = fopen("data.txt", "a");

    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    fprintf(fp, "\n%s,%lld,%s", data.name, data.NPM, data.country);

    fclose(fp);
}

void inputData(STUDENTS *data, int totalLine){
    int i;

    printf("\nName: ");
    scanf("%s", &data[totalLine - 1].name);
    printf("NPM: ");
    scanf("%lld", &data[totalLine - 1].NPM);
    printf("Country: ");
    scanf("%s", &data[totalLine - 1].country);
}

void rewriteFile(STUDENTS *data, int totalLine){
    FILE *fp;
    int i;

    fp = fopen("data.txt", "w");

    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    fprintf(fp, "Name,NPM,Country\n");
    for(i = 0; i < totalLine; i++){
        fprintf(fp, "%s,%lld,%s", data[i].name, data[i].NPM, data[i].country);
    }

    fclose(fp);
}

void selectionSort(STUDENTS *data, int totalLine){
    int i, j, min;
    STUDENTS temp;

    // sort name
    for(i = 0; i < totalLine - 1; i++){
        min = i;
        for(j = i + 1; j < totalLine; j++){
            if(strcmp(data[j].name, data[min].name) < 0){
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }

    rewriteFile(data, totalLine);
}


int main(){
    STUDENTS *student, temp_student;
    int count;
    FILE *fp;
    char temp[100];


    fp = fopen("data.txt", "r");

    if(fp == NULL){
        printf("File not found!");
        exit(1);
    }

    fgets(temp, 100, fp);
    count = 0;
    while(fgets(temp, 100, fp) != NULL){
        count++;
    }

    student = (STUDENTS *)calloc(count, sizeof(STUDENTS));
    readData(student, count);
    printData(student, count);

    // count++;
    // student = (STUDENTS *)realloc(student, count * sizeof(STUDENTS));

    // inputData(student, count);
    // appendData(student[count - 1]);

    // readData(student, count);
    // printData(student, count);

    selectionSort(student, count);

    readData(student, count);
    printData(student, count);


    fclose(fp);
    free(student);
    

    return 0;
}