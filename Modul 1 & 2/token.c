#include <stdio.h>
#include <string.h>

int main() {
    char sentece[1000];
    fgets(sentece, 1000, stdin);
    for (int i = 0; i < strlen(sentece); i++) {
        if (sentece[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", sentece[i]);
        }
    }
    return 0;
}