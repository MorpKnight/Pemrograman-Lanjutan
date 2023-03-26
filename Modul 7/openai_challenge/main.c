#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_LIST {
    int number;
    struct LINKED_LIST *next;
} DATA;

void sort_linked_list(DATA **data, int count){
    DATA *temp;
    int i, j;
    for(i = 0; i < count-1; i++){
        for(j = i+1; j < count; j++){
            if(data[i]->number > data[j]->number){
                temp = data[j];
                data[j] = data[i];
                data[i] = temp;
                printf("Swapped\n");
            }
        }
    }
}

int main(){
    DATA *list[100], *head;
    int i, count;
    char temp[10];
    FILE *fp;

    fp = fopen("input.txt", "r");

    count = 0;
    while(fgets(temp, 10, fp) != NULL){
        count++;
    }
    rewind(fp);

    for(i = 0; i < count; i++){
        list[i] = malloc(sizeof(DATA));
        list[i]->next = NULL;
        sscanf(temp, "%d", &list[i]->number);
        fgets(temp, 10, fp);
    }

    sort_linked_list(list, count);

    for(i = 0; i < count-1; i++){
        list[i]->next = list[i+1];
    }
    list[count-1]->next = NULL;

    head = list[0];
    while(head != NULL){
        printf("%d\n", head->number);
        head = head->next;
    }

    for(i = 0; i < count; i++){
        free(list[i]);
    }

    fclose(fp);

    return 0;
}
