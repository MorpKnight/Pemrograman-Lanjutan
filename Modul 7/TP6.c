#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void sortNode(Node *head){
    Node *current = head;
    Node *next = NULL;
    int temp;

    if(head == NULL){
        return;
    } else {
        while(current != NULL){
            next = current->next;

            while(next != NULL){
                if(current->data > next->data){
                    temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }

                next = next->next;
            }

            current = current->next;
        }
    }
}

void searchNode(Node *head){
    Node *current = head;
    int search;

    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &search);

    while(current != NULL){
        if(current->data == search){
            printf("Nilai %d ditemukan pada node ke-%d", search, current->data);
            break;
        } else {
            current = current->next;
        }

        if(current == NULL){
            printf("Nilai %d tidak ditemukan", search);
        }
    }
}

int main(){
    Node *head = NULL;
    Node *mahasiswa[3];
    Node *tail = NULL;

    int i = 0;
    printf("INPUT NILAI MAHASISWA\n");
    for(i = 0; i < 3; i++){
        // Membuat node baru, sebanyak 3 kali
        mahasiswa[i] = (Node *) malloc(sizeof(Node));
        printf("Nilai mahasiswa ke-%d: ", i+1);
        // Input nilai mahasiswa
        scanf("%d", &mahasiswa[i]->data);
        // Set nilai next dari node baru ke NULL
        mahasiswa[i]->next = NULL;
    }

    // Set nilai head ke node pertama
    head = mahasiswa[0];
    // Set nilai next dari node pertama ke node kedua
    mahasiswa[0]->next = mahasiswa[1];
    // Set nilai next dari node kedua ke node ketiga
    mahasiswa[1]->next = mahasiswa[2];
    // Set nilai tail ke node ketiga
    tail = mahasiswa[2];

    printf("\n\nOUTPUT NILAI MAHASISWA\n");
    // Melakukan looping untuk menampilkan nilai mahasiswa
    while(head != NULL){
        printf("Nilai ke-%d: %d\n", i, head->data);
        head = head->next;
    }

    // Memanggil fungsi sortNode untuk mengurutkan nilai mahasiswa
    sortNode(mahasiswa[0]);

    printf("\n\nOUTPUT NILAI MAHASISWA SETELAH DIURUTKAN\n");
    // Melakukan looping untuk menampilkan nilai mahasiswa
    i = 1;
    while(mahasiswa[0] != NULL){
        printf("Nilai ke-%d: %d\n", i, mahasiswa[0]->data);
        mahasiswa[0] = mahasiswa[0]->next;
        i++;
    }

    // Memanggil fungsi searchNode untuk mencari nilai mahasiswa
    searchNode(mahasiswa[0]);

    return 0;
}
