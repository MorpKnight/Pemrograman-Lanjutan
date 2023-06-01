#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode *nextPtr;
} StackNode;

typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int value){
    StackNodePtr newPtr;

    newPtr = malloc(sizeof(StackNode));

    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else {
        printf("%d tidak dapat dimasukan, memori tidak tersedia\n", value);
    }
}

int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr;

    int popValue;

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;

    free(tempPtr);
    return popValue;
}

void printStack(StackNodePtr currentPtr){
    if (currentPtr == NULL){
        printf("Stack kosong.\n\n");
    } else {
        printf("Stack-nya adalah:\n");

        while (currentPtr != NULL){
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

void clearStack(StackNodePtr *topPtr){
    StackNodePtr tempPtr;

    while (*topPtr != NULL){
        tempPtr = *topPtr;
        *topPtr = (*topPtr)->nextPtr;
        free(tempPtr);
    }
}

int main(){
    StackNodePtr stackPtr = NULL;
    StackNodePtr tempPtr;
    int value, mode;

    do {
        printf("1. Push\n2. Pop\n3. Clear stack\n4. Exit\n");
        printf("Pilih mode: ");
        scanf("%d", &mode);

        switch(mode){
            case 1:
                printf("Masukan nilai: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if (stackPtr != NULL){
                    printf("Nilai yang di-pop adalah %d\n", pop(&stackPtr));
                    printStack(stackPtr);
                } else {
                    printf("Stack kosong.\n");
                }
                break;
            case 3:
                clearStack(&stackPtr);
                printStack(stackPtr);
                break;
            case 4:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Mode tidak valid.\n");
                break;
        }
    } while(mode != 4);

    return 0;
}