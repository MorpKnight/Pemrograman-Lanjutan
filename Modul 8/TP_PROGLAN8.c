#include <stdio.h>
#include <omp.h>
#include <math.h>

int main() {
    int i, N, max_threads;
    float result;
    result = 0;

    // meminta input dari user
    printf("Masukkan nilai N: ");
    scanf("%d", &N);

    // menghitung jumlah thread yang tersedia
    max_threads = omp_get_max_threads();

    // set jumlah thread yang akan digunakan
    omp_set_num_threads(max_threads);
    
    // parallel region untuk menjalankan perintah for 
    #pragma omp parallel for reduction(+:result)
    // reduction(+:result) untuk menjumlahkan semua hasil yang didapat dari setiap thread
    for (i = 1; i <= N; i++) {
        // menghitung hasil penjumlahan
        result += 1/(pow(2, i));
    }

    // menampilkan hasil penjumlahan
    printf("Hasil penjumlahan = %lf\n", result);
    
    return 0;
}