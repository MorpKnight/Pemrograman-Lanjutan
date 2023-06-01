#include <stdio.h>
#include <stdlib.h>

// create struct for queue hospital
typedef struct queueNode {
    int data;
    struct queueNode *nextPtr;
} QueueNode;

typedef QueueNode *QueueNodePtr;

// push function
void push(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value){
    QueueNodePtr newPtr;

    newPtr = malloc(sizeof(QueueNode));

    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if (*headPtr == NULL){
            *headPtr = newPtr;
        } else {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    } else {
        printf("%d tidak dapat dimasukan, memori tidak tersedia\n", value);
    }
}

// pop function
int pop(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    QueueNodePtr tempPtr;

    int dequeueValue;

    tempPtr = *headPtr;
    dequeueValue = (*headPtr)->data;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL){
        *tailPtr = NULL;
    }

    free(tempPtr);
    return dequeueValue;
}

void printQueue(QueueNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("Queue kosong.\n\n");
    } else {
        printf("Queue-nya adalah:\n");

        while (currentPtr != NULL){
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

int main(){
    // init struct
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;

    // init variable
    int choice, value;
    value = 0;

    do {
        // print menu
        printf("1. Tambahkan pasien\n");
        printf("2. Panggil pasien\n");
        printf("3. Cek antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                value += 1;
                push(&headPtr, &tailPtr, value);
                printf("Pasien nomor %d telah ditambahkan.\n\n", value);
                break;
            case 2:
                if (headPtr == NULL){
                    printf("Tidak ada pasien.\n\n");
                } else {
                    printf("Pasien nomor %d dipanggil.\n\n", pop(&headPtr, &tailPtr));
                }
                break;
            case 3:
                printQueue(headPtr);
                break;
            case 4:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan salah.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}