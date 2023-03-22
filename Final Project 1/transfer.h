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

int check_user_id_target(long long user_id){
    user x;
    FILE *fp = fopen("db.txt", "r");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    while(fscanf(fp, "%d|%[^|]|%lf|%d", &x.user_id, x.name, &x.balance, &x.password) != EOF){
        if(x.user_id == user_id){
            fclose(fp);
            return 1;
        } else {
            fclose(fp);
            return 0;
        }
    }
}

int check_balance(long long user_id, double balance){
    user x;
    FILE *fp = fopen("db.txt", "r");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    while(fscanf(fp, "%d|%[^|]|%lf", &x.user_id, x.name, &x.balance) != EOF){
        if(x.user_id == user_id){
            if(x.balance >= balance){
                fclose(fp);
                return 1;
            } else {
                fclose(fp);
                return 0;
            }
        }
    }
}

void transfer_money(long long user_id, long long user_id_target, double balance){
    int check;
    user x;
    FILE *fp = fopen("db.txt", "r+");

    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    
    do {
        check = check_user_id(user_id);
    } while(check == 0);

    do {
        check = check_user_id_target(user_id_target);
    } while(check == 0);

    do {
        check = check_balance(user_id, balance);
    } while(check == 0);

    while(fscanf(fp, "%d|%[^|]|%lf|%d", &x.user_id, x.name, &x.balance, &x.password) != EOF){
        if(x.user_id == user_id){
            x.balance -= balance;
            fseek(fp, -1 * sizeof(x.balance), SEEK_CUR);
            fprintf(fp, "%lf", x.balance);
        } else if(x.user_id == user_id_target){
            x.balance += balance;
            fseek(fp, -1 * sizeof(x.balance), SEEK_CUR);
            fprintf(fp, "%lf", x.balance);
        }
    }
}