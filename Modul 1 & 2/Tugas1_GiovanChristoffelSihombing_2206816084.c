#include <stdio.h>
#include <string.h>
#include <stdarg.h>

// int main(){
//     char sentence[1000], *first_string;
//     fgets(sentence, 100, stdin);
//     first_string = strtok(sentence, " ");
//     while(first_string != NULL){
//         printf("%s\n", first_string);
//         first_string = strtok(NULL, " ");
//     }
//     return 0;
// }

// int main() {
//     char sentece[1000];
//     fgets(sentece, 1000, stdin);
//     for (int i = 0; i < strlen(sentece); i++) {
//         if (sentece[i] == ' ') {
//             printf("\n");
//         } else {
//             printf("%c", sentece[i]);
//         }
//     }
// }

int  sum (int count,...) {
    va_list list;
    int sum = 0;
    va_start(list, count);
    for (int i = 0; i < count; i++){
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}   

int min(int count,...) {
    va_list list;
    va_start(list, count);
    int min = va_arg(list, int);
    for (int i = 0; i < count; i++){
        int temp = va_arg(list, int);
        if (temp < min){
            min = temp;
        }
    }
    va_end(list);
    return min;
}

int max(int count,...) {
    va_list list;
    va_start(list, count);
    int max = va_arg(list, int);
    for (int i = 0; i < count; i++){
        int temp = va_arg(list, int);
        if (temp > max){
            max = temp;
        }
    }
    va_end(list);
    return max;
}