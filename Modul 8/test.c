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

void gaussJordanElimination(double matrix[][10], int baris, int kolom, int threadUsed) {
    int i, j, k;
    int step = 0;

    omp_set_num_threads(threadUsed);
    
    for (i = 0; i < baris; i++) {
        if (matrix[i][i] == 0) {
            int pivot_found = 0;
            int pivot_row = -1; // Inisialisasi pivot_row dengan nilai -1
            
            #pragma omp parallel for shared(matrix) reduction(||:pivot_found) // Menggunakan reduction untuk menggabungkan hasil pivot_found dari semua thread
            for (j = i + 1; j < baris; j++) {
                if (matrix[j][i] != 0) {
                    pivot_row = j;
                    pivot_found = 1;
                }
            }
            
            if (pivot_found) {
                SwapBaris(matrix, i, pivot_row, kolom);
                #pragma omp master // Hanya thread master yang melakukan printStep dan printMatrix
                {
                    printStep(++step, i, pivot_row);
                    printMatrix(matrix, baris, kolom);
                }

            } else {
                #pragma omp master // Hanya thread master yang melakukan print
                {
                    printf("Tidak dapat menyelesaikan operasi Gauss-Jordan. Terdapat baris dengan elemen semua nol.\n");
                }
                return;
            }
        }
         
        double pivot = matrix[i][i];
        #pragma omp parallel for shared(matrix) private(j)
        for (j = 0; j < kolom; j++) {
            matrix[i][j] /= pivot;
        }
        #pragma omp master // Hanya thread master yang melakukan printStep dan printMatrix
        {
            printStep(++step, i, i);
            printMatrix(matrix, baris, kolom);
        }

        #pragma omp parallel for shared(matrix) private(j, k)
        for (j = i + 1; j < baris; j++) {
            double faktor = matrix[j][i];
            for (k = 0; k < kolom; k++) {
                matrix[j][k] -= faktor * matrix[i][k];
            }
            #pragma omp master // Hanya thread master yang melakukan printStep dan printMatrix
            {
                printStep(++step, j, i);
                printMatrix(matrix, baris, kolom);
            }
        }

        #pragma omp barrier // Pastikan semua thread selesai sebelum melanjutkan
        #pragma omp parallel for shared(matrix) private(j, k)
        for (j = 0; j < i; j++) {
            double faktor = matrix[j][i];
            for (k = 0; k < kolom; k++) {
                matrix[j][k] -= faktor * matrix[i][k];
            }
            #pragma omp master // Hanya thread master yang melakukan printStep dan printMatrix
            {
                printStep(++step, j, i);
                printMatrix(matrix, baris, kolom);
            }
        }
    }
}

// void reducedEchelonForm(double matrix[][10], int baris, int kolom, int threadUsed) {
//     gaussJordan(matrix, baris, kolom, threadUsed);

//     int i, j;
//     for (i = baris - 1; i >= 0; i--) {
//         // Cari pivot pertama yang bukan nol dalam baris i
//         for (j = 0; j < kolom - 1; j++) {
//             if (matrix[i][j] != 0) {
//                 break;
//             }
//         }

//         if (j == kolom - 1) {
//             // Baris hanya berisi nol, lewati
//             continue;
//         }

//         // Bagi setiap elemen di baris i dengan elemen di pivot
//         double pivot = matrix[i][j];
//         for (int k = j; k < kolom; k++) {
//             matrix[i][k] /= pivot;
//         }

//         // Kurangi setiap elemen di baris lain dengan elemen di baris i dikali faktor
//         for (int k = i - 1; k >= 0; k--) {
//             if (matrix[k][j] != 0) {
//                 double faktor = matrix[k][j];
//                 for (int l = j; l < kolom; l++) {
//                     matrix[k][l] -= faktor * matrix[i][l];
//                 }
//             }
//         }
//     }
// }

int main() {
    int row, col, i, j, threadUsed;
    double matrix[10][10];

    // Input jumlah baris dan kolom
    printf("Masukkan jumlah baris: ");
    scanf("%d", &row);

    printf("Masukkan jumlah kolom: ");
    scanf("%d", &col);

    // Input jumlah thread
    do {
        printf("Masukkan jumlah thread: (1-%d) ", omp_get_max_threads());
        scanf("%d", &threadUsed);
    } while (threadUsed < 1 || threadUsed > omp_get_max_threads());

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
    gaussJordanElimination(matrix, row, col, threadUsed);
    // Print matriks hasil Gauss-Jordan
    printf("Hasil Gauss-Jordan:\n");
    printMatrix(matrix, row, col);

    return 0;
}