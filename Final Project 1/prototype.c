#include <stdio.h>
#include <stdlib.h>
#include <checkaccount.h>
#include <newaccount.h>
#include <transfer.h>

typedef struct USER {
    double balance;
    char name[100];
    long long user_id;
} user;

void show_menu(){
    int choice;
    user user;
    printf("Welcome to the ATM\n");
    printf("Insert your ID: ");
    scanf("%lld", &user.user_id);
}

int main(){

    return 0;
}