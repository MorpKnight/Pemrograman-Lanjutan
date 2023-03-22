#include <stdio.h>
#include <stdlib.h>

typedef struct USER {
    long long user_id;
    char name[100];
    double balance;
    int password;
} user;

int check_user_id(long long user_id){
    user x;
    int password;
    FILE *fp = fopen("db.txt", "r");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    while(fscanf(fp, "%d|%[^|]|%lf|%d", &x.user_id, x.name, &x.balance, &x.password) != EOF){
        if(x.user_id == user_id){
            do {
                printf("Masukkan password: ");
                scanf("%d", &password);
            } while(password != x.password);
            fclose(fp);
            break;
            return 1;
        } else {
            fclose(fp);
            return 0;
        }
    }
}

void print_account_details(long long user_id){
    user x;
    int check;
    FILE *fp = fopen("db.txt", "r");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    while(fscanf(fp, "%d|%[^|]|%lf|%d", &x.user_id, x.name, &x.balance, &x.password) != EOF){
        if(x.user_id == user_id){
            do {
                check = check_user_id(user_id);
            } while(check == 0);

            printf("Nama: %s", x.name);
            printf("User ID: %lld", x.user_id);
            printf("Saldo: %lf", x.balance);
            fclose(fp);
        }
    }
}