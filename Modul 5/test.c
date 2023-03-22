#include <stdio.h>
#include <stdlib.h>

int main(){
    char *kalimat = NULL;
    int size, index;
    char c;
    size = 0;
    index = 0;

    printf("Masukkan kalimat: ");
    do {
        c = getchar();
        if (c != '\n'){
            if(index == size){
                size += 1;
                kalimat = (char *) realloc(kalimat, size * sizeof(char));
            }
            kalimat[index++] = c;
        }
    } while (c != '\n');

    for(int i = 0; i < size; i++){
        printf("%c", kalimat[i]);
    }
    printf("\n%s", *kalimat);

    free(kalimat);
    return 0;
}