#include <stdio.h>
#include <stdlib.h>

typedef struct DATA {
    int value;
    struct DATA *next;
} DATA;

int main(){
    int i, count;
    DATA *data, *head;

    printf("Berapa urutan data: ");
    scanf("%d", &count);

    data = (DATA*) calloc(count, sizeof(DATA));

    for(i = 0; i < count; i++){
        data[i] = malloc(sizeof(DATA));
        data[i].next = NULL;
        printf("Masukkan data ke-%d: ", i+1);
        scanf("%d", &data[i].value);
    }

    free(data);
    return 0;
}

