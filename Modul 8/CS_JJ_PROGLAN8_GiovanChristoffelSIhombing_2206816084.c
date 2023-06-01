#include <stdio.h>
#include <omp.h>

// Tukar baris1 dan baris2
void SwapBaris(double matrix[][10], int baris1, int baris2, int kolom) {
    int i;
    double temp;

    // Tukar setiap elemen di baris1 dengan elemen di baris2
    for (i = 0; i <= kolom; i++) {
        temp = matrix[baris1][i];
        matrix[baris1][i] = matrix[baris2][i];
        matrix[baris2][i] = temp;
    }
}

// Print matriks
void printMatrix(double matrix[][10], int baris, int kolom) {
    int i, j;
    for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Print langkah
void printStep(int step, int baris1, int baris2) {
    printf("\nLangkah %d: Tukar baris %d dengan baris %d\n", step, baris1 + 1, baris2 + 1);
}

// Operasi Gauss-Jordan
void gaussJordan(double matrix[][10], int baris, int kolom, int threadUsed) {
    int i, j, k;
    int step = 0;

    // Set jumlah thread yang digunakan
    omp_set_num_threads(threadUsed);
    
    // Operasi Gauss-Jordan
    for (i = 0; i < baris; i++) {
        // Jika elemen di diagonal utama 0, cari baris lain yang elemennya tidak 0
        if (matrix[i][i] == 0) {
            // Cari baris lain yang elemennya tidak 0
            int pivot_found = 0;
            // Baris yang elemennya tidak 0
            int pivot_row;
            
            // Cari baris lain yang elemennya tidak 0
            for (j = i + 1; j < baris; j++) {
                // Jika elemen di baris j tidak 0, maka baris j menjadi baris yang elemennya tidak 0
                if (matrix[j][i] != 0) {
                    // Baris j menjadi baris yang elemennya tidak 0
                    pivot_row = j;
                    // Berhenti mencari
                    pivot_found = 1;
                    // Tukar baris i dengan baris j
                    break;
                }
            }
            
            // Jika tidak ditemukan baris lain yang elemennya tidak 0, maka operasi Gauss-Jordan tidak dapat dilakukan
            if (pivot_found) {
                // Tukar baris i dengan baris pivot_row
                SwapBaris(matrix, i, pivot_row, kolom);
                // Print langkah
                printStep(++step, i, pivot_row);
                // Print matriks
                printMatrix(matrix, baris, kolom);

                // Jika elemen di diagonal utama 0, maka operasi Gauss-Jordan tidak dapat dilakukan
            } else {
                // Print matriks
                printf("Tidak dapat menyelesaikan operasi Gauss-Jordan. Terdapat baris dengan elemen semua nol.\n");
                return;
            }
        }
         
        double pivot = matrix[i][i];
        // Menggunakan parallel for
        #pragma omp parallel for shared(matrix) private(j)
        // Bagi setiap elemen di baris i dengan elemen di diagonal utama
        for (j = 0; j < kolom; j++) {
            printf("Membagi arr[%d][%d] dengan %.2f menggunakan thread %d\n", i, j, pivot, omp_get_thread_num());
            // Menggunakan omp atomic karena setiap thread mengakses elemen yang sama
            #pragma omp atomic
            matrix[i][j] /= pivot;
        }
        printStep(++step, i, i);
        printMatrix(matrix, baris, kolom);

        // Menggunakan parallel for
        #pragma omp parallel for shared(matrix) private(j, k)
        // Kurangi setiap elemen di baris lain dengan elemen di baris i dikali faktor
        for (j = i + 1; j < baris; j++) {
            // Faktor yang akan dikalikan ke setiap elemen di baris lain
            double faktor = matrix[j][i];
            for (k = 0; k < kolom; k++) {
                printf("Mengurangi arr[%d][%d] dengan %.2f * arr[%d][%d] menggunakan thread %d\n", j, k, faktor, i, k, omp_get_thread_num());
                // Menggunakan omp atomic karena setiap thread mengakses elemen yang sama
                #pragma omp atomic
                matrix[j][k] -= faktor * matrix[i][k];
            }
            printStep(++step, j, i);
            printMatrix(matrix, baris, kolom);
        }

        // Menggunakan parallel for
        #pragma omp barrier
        #pragma omp parallel for shared(matrix) private(j, k)
        // Kurangi setiap elemen di baris lain dengan elemen di baris i dikali faktor
        for (j = 0; j < i; j++) {
            // Faktor yang akan dikalikan ke setiap elemen di baris lain
            double faktor = matrix[j][i];
            for (k = 0; k < kolom; k++) {
                printf("Perkalian arr[%d][%d] dengan %.2f * arr[%d][%d] menggunakan thread %d\n", j, k, faktor, i, k, omp_get_thread_num());
                // Menggunakan omp atomic karena setiap thread mengakses elemen yang sama
                #pragma omp atomic
                // Kurangi setiap elemen di baris lain dengan elemen di baris i dikali faktor
                matrix[j][k] -= faktor * matrix[i][k];
            }
            printStep(++step, j, i);
            printMatrix(matrix, baris, kolom);
        }
    }
}

int main() {
    int row, col, i, j, threadUsed, check;
    double matrix[10][10];
    check = 0;

    // Input jumlah baris dan kolom
    printf("Masukkan jumlah baris: ");
    scanf("%d", &row);

    printf("Masukkan jumlah kolom: ");
    scanf("%d", &col);

    // Input jumlah thread
    printf("Masukkan jumlah thread: (1-%d) ", omp_get_max_threads());
    scanf("%d", &threadUsed);
    if(threadUsed < 1 || threadUsed > omp_get_max_threads()) {
        printf("Jumlah thread yang diinginkan terlalu banyak, tetap akan dieksekusi dengan jumlah thread yang dimasukkan!\n");
    }

    // Input elemen-elemen matriks
    printf("Masukkan elemen-elemen matriks:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Print matriks awal
    printf("\nMatriks awal:\n");
    printMatrix(matrix, row, col);

    // Operasi Gauss-Jordan
    gaussJordan(matrix, row, col, threadUsed);

    // Print matriks hasil Gauss-Jordan
    printf("Hasil Gauss-Jordan:\n");
    printMatrix(matrix, row, col);

    return 0;
}