#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int num;
    struct NODE *next;
} Node;

Node *insertNode(Node *head, int *totalNodes){
    Node *current = NULL;
    Node *new = NULL;
    int i;

    printf("Nodes: ");
    scanf("%d", totalNodes);

    printf("Linked lists: ");
    for(i = 0; i < *totalNodes; i++){
        new = (Node *) malloc (sizeof(Node));
        scanf("%d", &new->num);
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
    int i;

    while(current != NULL){
        printf("%d ", current->num);
        current = current->next;
    }
}

void oddPalindrom(Node *head, int totalNodes){
    int i, steps;
    Node *current1 = head;
    Node *current2 = head;
    
    steps = (totalNodes - 1)/2;

    for(i = 0; i < steps; i++){
        current2 = current2->next;
    }

    Node *prev = NULL;
    Node *current = current2->next;
    Node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    while(prev != NULL){
        if(current1->num != prev->num){
            printf("GA PALINDROM OIT");
            return;
        }
        current1 = current1->next;
        prev = prev->next;
    }

    printf("PALLINDROM HARUSNYA");
}

void evenPalindrom(Node *head, int totalNodes){
    int i, steps;
    Node *current1 = head;
    Node *current2 = head;
    
    steps = totalNodes/2;

    for(i = 0; i < steps; i++){
        current2 = current2->next;
    }

    Node *prev = NULL;
    Node *current = current2->next;
    Node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    while(prev != NULL){
        if(current1->num != prev->num){
            printf("GA GA, GA PALINDROM");
            return;
        }
        current1 = current1->next;
        prev = prev->next;
    }

    printf("PALLINDROM HARUSNYA");
}

void checkPalindrom(Node *head, int totalNodes){
    int i, steps;
    Node *current1 = head;
    Node *current2 = head;
    
    if(totalNodes%2 == 0){
        steps = totalNodes/2;
    } else {
        steps = (totalNodes-1)/2;
    }

    for(i = 0; i < steps; i++){
        current2 = current2->next;
    }

    Node *prev = NULL;
    Node *current = current2->next;
    Node *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    while(prev != NULL){
        if(current1->num != prev->num){
            printf("GA GA, GA PALINDROM");
            return;
        }
        current1 = current1->next;
        prev = prev->next;
    }

    printf("PALLINDROM HARUSNYA");
}

int main(){
    Node *head = NULL;
    int totalNodes;
    
    head = insertNode(head, &totalNodes);
    checkPalindrom(head, totalNodes);

    return 0;
}