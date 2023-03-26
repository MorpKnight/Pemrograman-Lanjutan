#include <stdio.h>
#include <stdlib.h>

int main() {
    char input;
    int num, product, total;
    do {
        total = 1;
        printf("Masukkan bilangan genap (untuk berhenti masukkan 'E' atau 'e'): ");
        while (scanf("%d", &num) == 1) {
            if (num % 2 == 0) {
                product = num;
                total *= product;
            }
            printf("Masukkan bilangan genap (untuk berhenti masukkan 'E' atau 'e'): ");
        }
        scanf("%c", &input); // membersihkan input buffer
        if (input != 'E' && input != 'e') {
            printf("Input tidak valid, silakan coba lagi.\n");
            continue;
        }
        printf("Total perkalian bilangan genap adalah %d\n", total);
        printf("Masukkan 'X' atau 'x' untuk mengulang program, atau tekan tombol apapun untuk keluar: ");
        scanf("%c", &input);
    } while (input == 'X' || input == 'x');
    return 0;
}
