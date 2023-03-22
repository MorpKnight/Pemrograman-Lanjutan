#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct USER {
    long long user_id;
    char name[100];
    double balance;
    int password;
} user;

long long generate_user_id(){
    int i;
    long long num = 0;

    srand(time(NULL));
    for (i = 0; i < 16; i++) {
        num = num * 10 + rand() % 10;
    }
    return num;
}

void register_new_account(){
    user x;

    printf("Masukkan nama: ");
    scanf("%s", x.name);
    x.user_id = generate_user_id();
    printf("User ID anda adalah: %lld", x.user_id);
    printf("Masukkan password: ");
    scanf("%d", &x.password);
    x.balance = 0;
}

void append_new_account(user x){
    FILE *fp = fopen("db.txt", "a");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    fprintf(fp, "%lld|%s|%lf|%d", x.user_id, x.name, x.balance, x.password);
    fclose(fp);
}