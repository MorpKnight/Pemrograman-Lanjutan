#include <stdio.h>
#include <stdlib.h>

int main() {
    char input, lanjut;
    int num, product, total;
    do {
        // reset total
        total = 1;
        printf("Masukkan bilangan genap (untuk berhenti masukkan 'E' atau 'e'): ");
        
        // loop sampai user memasukkan 'E' atau 'e'
        while (scanf("%d", &num) == 1) {
            if (num % 2 == 0) {
                product = num;
                total *= product;
            }
            printf("Masukkan bilangan genap (untuk berhenti masukkan 'E' atau 'e'): ");
        }

        // jika user memasukkan 'E' atau 'e', maka program akan berhenti
        scanf("%c", &input);
        if (input != 'E' && input != 'e') {
            printf("Input tidak valid, silakan coba lagi.\n");
            // skip ke awal loop
            continue;
        }

        // menampilkan hasil perkalian bilangan genap
        printf("Total perkalian bilangan genap adalah %d\n", total);

        // menanyakan apakah user ingin mengulang program
        printf("Masukkan 'X' atau 'x' untuk mengulang program, atau tekan tombol apapun untuk keluar: ");

        // input buffer
        scanf("\n");
        // input untuk menentukan apakah user ingin mengulang program
        scanf("%c", &lanjut);
    } while (lanjut == 'X' || lanjut == 'x');
    return 0;
}
