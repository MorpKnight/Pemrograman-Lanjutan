#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
    char makanan[50];
    int harga, index;
    struct NODE *next;
} Node;

Node *insertNode(Node *head){
    Node *current = NULL;
    Node *new = NULL;
    int i, total_food;

    printf("Masukan jumlah makanan: ");
    scanf("%d", &total_food);
    printf("\n");

    for(i = 0; i < total_food; i++){
        new = (Node *) malloc(sizeof(Node));
        printf("Masukan nama makanan: ");
        scanf("%s", &new->makanan);
        printf("Masukan harga makanan: Rp");
        scanf("%d", &new->harga);
        new->index = i+1;
        printf("\n");
        new->next = NULL;

        if(head == NULL){
            head = new;
            current = new;
        } else {
            current->next = new;
            current = new;
        }
    }

    return head;
}

void printNode(Node *head){
    Node *current = head;
    int i, total_price;

    i = 1;
    total_price = 0;
    printf("\nOUTPUT\n");
    while(current != NULL){
        printf("Makanan ke-%d\n", i);
        printf("%s\n", current->makanan);
        printf("%d\n\n", current->harga);
        total_price += current->harga;
        i++;
        current = current->next;
    }

    printf("Total harga seluruh makanan: Rp %d", total_price);
}

void deleteNode(Node *head){
    Node *current = head;
    Node *current_next = current->next;
    int index;

    printf("Mau delete index ke berapa: ");
    scanf("%d", &index);
    printf("\n");

    while(current != NULL){
        if(current->index == index){
            current->next = current_next->next;
        }
        current = current->next;
    }
}

int main(){
    Node *head = NULL;
    int i;

    head = insertNode(head);
    printNode(head);

    printf("Ingin cek kembali (1/0): ");
    scanf("%d", &i);

    deleteNode(head);
    printNode(head);

    return 0;
}