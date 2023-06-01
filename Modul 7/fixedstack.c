#include <stdio.h>

// push ke stack
void pushStack(int *stack, int *top, int maxSize, int value){
    // cek apakah stack penuh
    if(*top == maxSize - 1){
        printf("Stack is full\n");
    }else{
        // apabila tidak penuh, maka top diincrement dan stack[top] diisi dengan value
        *top = *top + 1;
        stack[*top] = value;
    }
}

// pop dari stack
int popStack(int *stack, int *top){
    int value = 0;
    // cek apakah stack kosong
    if(*top == -1){
        printf("Stack is empty\n");
    }else{
        // apabila tidak kosong, maka value diisi dengan stack[top] dan stack[top] diisi dengan 0
        value = stack[*top];
        stack[*top] = 0;
        *top = *top - 1;
    }

    // return value
    return value;
}

// menampilkan stack
void printStack(int *stack, int maxSize){
    int i;
    for(i = 0; i < maxSize; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// mengecek apakah stack penuh
void checkFull(int *stack, int maxSize, int top){
    if(top == maxSize - 1){
        printf("Stack is full\n");
    }else{
        printf("Stack is not full\n");
    }
}

// mengecek apakah stack kosong
void checkEmpty(int *stack, int maxSize, int top){
    if(top == -1){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
}

int main(){
    int maxSize = 5;
    int stack[maxSize], top, i, appendNumber, popNumber;

    // inisialisasi stack
    top = -1;

    // pembuktian stack kosong
    checkEmpty(stack, maxSize, top);

    // push ke stack
    for(i = 0; i < maxSize; i++){
        stack[i] = 0;
    }

    // menampilkan stack
    printStack(stack, maxSize);

    // push ke stack
    for(i = 0; i < maxSize; i++){
        pushStack(stack, &top, maxSize, i + 1);
        printStack(stack, maxSize);
    }

    // pembuktian stack penuh
    checkFull(stack, maxSize, top);

    // pop dari stack
    for(i = 0; i < maxSize; i++){
        popNumber = popStack(stack, &top);
        printf("Pop number: %d\n", popNumber);
        printStack(stack, maxSize);
    }

    // pembuktian stack kosong
    printStack(stack, maxSize);

    return 0;
}