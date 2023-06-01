#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
} TreeNode;

typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value){
    if(*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));

        if(*treePtr != NULL){
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("Tidak dapat dimasukan, memori tidak tersedia\n", value);
        }
    } else {
        if(value < (*treePtr)->data){
            insertNode(&((*treePtr)->leftPtr), value);
        } else if(value > (*treePtr)->data){
            insertNode(&((*treePtr)->rightPtr), value);
        } else {
            printf("duplikat\n");
        }
    }
}

void deleteNode(TreeNodePtr *treePtr, int value){
    if(*treePtr != NULL){
        if(value < (*treePtr)->data){
            deleteNode(&((*treePtr)->leftPtr), value);
        } else if(value > (*treePtr)->data){
            deleteNode(&((*treePtr)->rightPtr), value);
        } else {
            if((*treePtr)->leftPtr == NULL && (*treePtr)->rightPtr == NULL){
                free(*treePtr);
                *treePtr = NULL;
            } else if((*treePtr)->leftPtr == NULL){
                TreeNodePtr tempPtr = *treePtr;
                *treePtr = (*treePtr)->rightPtr;
                free(tempPtr);
            } else if((*treePtr)->rightPtr == NULL){
                TreeNodePtr tempPtr = *treePtr;
                *treePtr = (*treePtr)->leftPtr;
                free(tempPtr);
            } else {
                TreeNodePtr tempPtr = (*treePtr)->rightPtr;
                while(tempPtr->leftPtr != NULL){
                    tempPtr = tempPtr->leftPtr;
                }
                (*treePtr)->data = tempPtr->data;
                deleteNode(&((*treePtr)->rightPtr), tempPtr->data);
            }
        }
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void searchNode(TreeNodePtr treePtr, int value){
    if(treePtr != NULL){
        if(value < treePtr->data){
            searchNode(treePtr->leftPtr, value);
        } else if(value > treePtr->data){
            searchNode(treePtr->rightPtr, value);
        } else {
            printf("Data ditemukan\n");
        }
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void printNode(TreeNodePtr treePtr){
    if(treePtr != NULL){
        printNode(treePtr->leftPtr);
        printf("%d ", treePtr->data);
        printNode(treePtr->rightPtr);
    }
}

void printInOrderTraversal(TreeNodePtr treePtr){
    if(treePtr != NULL){
        printInOrderTraversal(treePtr->leftPtr);
        printf("%d ", treePtr->data);
        printInOrderTraversal(treePtr->rightPtr);
    }
}

int main(){
    TreeNodePtr rootPtr = NULL;
    TreeNodePtr newPtr;
    TreeNodePtr currentPtr;
    TreeNodePtr tempPtr;

    int value, mode;

    do {
        printf("Masukan mode:\n1. Menambahkan Node\n2. Menghapus Node\n3. Mencari Node\n4. Print Node\n5. Exit\n");
        scanf("%d", &mode);
        switch(mode){
            case 1:
                printf("Masukan nilai: ");
                scanf("%d", &value);
                insertNode(&rootPtr, value);
                printNode(rootPtr);
                break;
            case 2:
                printf("Masukan nilai: ");
                scanf("%d", &value);
                deleteNode(&rootPtr, value);
                printNode(rootPtr);
                break;
            case 3:
                printf("Masukan nilai: ");
                scanf("%d", &value);
                searchNode(rootPtr, value);
                break;
            case 4:
                printInOrderTraversal(rootPtr);
                break;
            case 5: 
                printf("Terima kasih telah menggunakan program ini\n");
                break;
            default:
                break;
        }
    } while(mode != 5);

    return 0;
}