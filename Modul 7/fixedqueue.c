#include <stdio.h>

// untuk push ke queue
void pushQueue(int *queue, int *rear, int maxSize, int value){
    // cek apakah queue penuh
    if(*rear == maxSize - 1){
        printf("Queue is full\n");
    }else{
        *rear = *rear + 1;
        queue[*rear] = value;
    }
}

// untuk pop dari queue
int popQueue(int *queue, int *front, int *rear){
    int value = 0;
    // cek rear dan front apakah sama
    if(*front == *rear){
        printf("Queue is empty\n");
    }else{
        // jika sama, maka front diincrement dan value diisi dengan queue[front]
        *front = *front + 1;
        value = queue[*front];
        queue[*front] = 0;
    }

    // return value
    return value;
}

// untuk mengecek apakah queue penuh
void checkFull(int *queue, int maxSize, int front, int rear){
    if(rear == maxSize - 1){
        printf("Queue is full\n");
    }else{
        printf("Queue is not full\n");
    }
}

// untuk mengecek apakah queue kosong
void checkEmpty(int *queue, int maxSize, int front, int rear){
    if(front == rear){
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");
    }
}

// untuk menampilkan queue
void printQueue(int *queue, int maxSize){
    int i;
    for(i = 0; i < maxSize; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int maxSize = 5;
    int queue[maxSize], front, rear, i, appendNumber, popNumber;

    // inisialisasi queue
    front = -1;
    rear = -1;

    // mengisi queue dengan 0
    for(i = 0; i < maxSize; i++){
        queue[i] = 0;
    }

    // meminta inputan user dan menampilkan queue
    printf("Append number: ");
    for(i = 0; i < maxSize; i++){
        scanf("%d", &appendNumber);
        pushQueue(queue, &rear, maxSize, appendNumber);
        printQueue(queue, maxSize);
    }

    // pop queue dan menampilkan queue
    popNumber = popQueue(queue, &front, &rear);
    printf("\nPop number: %d\n", popNumber);
    printQueue(queue, maxSize);

    return 0;
}