#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
    int data;
    struct queueNode *nextPtr;
} QueueNode;

typedef QueueNode *QueueNodePtr;

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

void clearQueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
    QueueNodePtr tempPtr;

    while (*headPtr != NULL){
        tempPtr = *headPtr;
        *headPtr = (*headPtr)->nextPtr;
        free(tempPtr);
    }

    *tailPtr = NULL;
}

int main(){
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int mode, val, popVal;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Clear queue\n4. Exit\n");
        printf("Masukan mode >");
        scanf("%d", &mode);

        switch(mode){
            case 1:
                printf("Masukan nilai >");
                scanf("%d", &val);
                psuh(&headPtr, &tailPtr, val);
                printQueue(headPtr);
                break;
            case 2:
                popVal = pop(&headPtr, &tailPtr);
                printf("Nilai yang di-pop adalah %d\n", popVal);
                printQueue(headPtr);
                break;
            case 3:
                clearQueue(&headPtr, &tailPtr);
                printQueue(headPtr);
                break;
            case 4:
                printf("Keluar dari program\n");
                break;
            default:
                printf("Mode tidak ditemukan\n");
                break;
        }
    } while (mode != 4);

    printQueue(headPtr);

    return 0;
}