#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKED_LIST {
    int data;
    struct LINKED_LIST *next;
} linked_list;

int main(){
    linked_list *head = NULL;  //create a pointer to the head of the list
    linked_list *current = NULL; //create a pointer to the current position
    linked_list *new = NULL; //create a pointer to the new node

    int i = 0;
    for (i = 0; i < 10; i++){ //loop 0..9
        new = (linked_list *) malloc(sizeof(linked_list)); //allocate memory for the new node
        new->data = i; //assign the data to the new node
        new->next = NULL; //set next pointer to NULL

        if (head == NULL){ //if the head == NULL, there are no nodes in the list
            head = new; //set the head pointer to the new node
            current = new; //set the current pointer to the new node
        } else {
            current->next = new; //set the next pointer of the current node to the new node
            current = new; //set the current pointer to the new node
        }
    }

    current = head; //set the current pointer to the head of the list
    while (current != NULL){ //loop until the current pointer is NULL
        printf("%d ", current->data); //print data
        current = current->next; //set the current pointer to the next node
    }

    return 0;
}