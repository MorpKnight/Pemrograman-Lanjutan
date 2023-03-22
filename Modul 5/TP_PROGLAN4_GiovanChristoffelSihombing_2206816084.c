/*
Menjawab soal nomor 3 TP Proglan 4
Kode dan Analisa
*/

#include <stdio.h>

int binary_search(int *arr, int x, int low, int high){
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            // apabila elemen middlenya (array) merupakan elemen yang dicari, maka akan langsung mereturn nilai indeks elemen tersebut
            return mid;
        }

        if(arr[mid] < x){
            // jika elemen pada middle array <= elemen yang dicari, pencarian akan dibatasi ke separuh array (kanan)
            low = mid + 1;
        } else {
            // jika elemen pada middle array >= elemen yang dicari, pencarian akan dibatasi ke separuh array (kiri)
            high = mid -1;
        }
    }
    // akan mereturn -1 apabila elemen tidak ditemukan
    return -1;
}

int main(){
    int i, j, requested_number, result, n, arr[] = {77, 78, 83, 83, 90, 98, 100};
    n = sizeof(arr)/sizeof(arr[0]); // menghitung panjang array

    printf("Masukan angka: ");
    scanf("%d", &requested_number); // meminta angka yang akan dicari indeksnya pada array yang telah disediakan

    result = binary_search(arr, requested_number, 0, n-1); //menggunakan fungsi binary_search untuk mendapatkan indeks dari elemen yang dicari
    if(result == -1){
        printf("Tidak dapat ditemukan!"); // apabila elemen tidak ada pada array
    } else {
        printf("Terdapat pada indeks ke-%d", result); /// apabila elemen ada, dan akan print out index nya
    }

    return 0;
}