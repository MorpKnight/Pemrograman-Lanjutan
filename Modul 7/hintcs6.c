#include <stdio.h>
#include <stdlib.h>


struct node{
    //Silahkan masukan data yang diperlukan

    //Masukan variabel yang menunjukan pointer ke node selanjutnya

};

void insertNode( struct node * head, struct node * tail, struct node * temp, int n);
void printList(struct node * head, struct node * tail, struct node * temp);
void removeList( struct node * head, struct node * tail, struct node * temp, int n);

/*
Jika ingin menggunakan fungsi, masukan paramter yang dibutuhkan
void insertNode({Isi dengan parameter});
void printList({Isi dengan paramter});
void removeList({Isi dengan paramter});

HINT Parameter:
- Masukan struct node dengan tipe pointer sebagai variabel HEAD, tail, dan temp
- Masukan variabel lainnya jika diperlukan
*/


int main(){
        //Silahkan inisiasikan dan deklarasikan variabel yang diperlukan

        //Samakan persepsi
        //head meruupakan node pertama (start)
        struct node * head = NULL;
        //tail meruupakan node terakhir (end)
        struct node * tail = NULL;
        //temp meruupakan node yang digunakan untuk menunjukan node yang sedang di proses
        struct node * temp = NULL;
        
        //Alokasi memory pada node head sekaligus pembuatan node pertama
        head = (struct node *)malloc(sizeof(struct node));

        /*
        Inisiasi node pertama
        Pada saat inisiasi node pertama hanya ada 1 node (sudah dibuat pada alokasi memory di atas) dan node tersebut belum memiliki node selanjutnya
        Susunan node adalah sebagai berikut
        node(head node dan tail node) -> NULL
        Ilustrasikan dalam bentuk code:
        Clue:
        1. node head belum memiliki node selanjutnya (next dari node head adalah NULL)
        2. Node tail memiliki posisi alamat yang sama dengan node head (Kode: tail = head)
        */

       //Silahkan tambahkan kode sesuai kebutuhan Anda

       //Masukan paramter yang sesuai dengan fungsi yang telah dibuat
        insertNode();
        printList();
    
}

//Jangan lupa untuk masukan paramter yang sesuai dengan fungsi yang telah dibuat
// Fungsi untuk memasukan data pada linked list
void insertNode(struct node * head, struct node * tail, struct node * temp, int n){

    int i;
    //Metode iterasi bebas, tidak mesti menggunakan for
    for(i = 0; i < n; i++){
            //Inisiasi alokasi memory pada node temp (seperti yang dilakukan node head)
            //temp merupakan node yang baru dibentuk
            temp = (struct node *)malloc(sizeof(struct node));

            //Masukan code untuk menginput data yang dibutuhkan pada node temp 


            //Dikarenakan temp merupakan node baru, maka asumsikan dia berada di akhir linked list.
            //Diikarenakan temp berada di akhir link listed, maka temp belum memiliki node selanjutnya (node selanjutnya bernilai NULL)
            //Masukan kode untuk memenuhi kedua clue di atas:


            //Node baru sudah dibentuk, maka hubungkanlah dengan node terakhir dari node yang lama
            /* Contoh, misal data yang anda input sudah memiliki 4 nodes:
            Node sebelum : head ->node1 -> node2 -> node3 -> node4 (tail) -> NULL
            Kan ada node temp yang baru terbentuk ya, tapi belom dihubungin ke link listed yang ada, jadi sok mangga atuh dihubungin
            Sehingga node setelahnya adalah:
            head -> node1 -> node2 -> node3 -> node4 (tail) -> node5 (temp) -> NULL
            Masukan code untuk memenuhi clue di atas:
            */

           /*
           BELUM SELESAI
           Masih melanjutkan contoh di atas
           Node tail masih berada di node4, belum di node5 (temp)
           Buatlah kode untuk memindahkan node tail ke node5 (temp)
           Sehingga hasil akhirnya:
           head -> node1 -> node2 -> node3 -> node4 -> node5 (tail) -> NULL
           Masukan code untuk memenuhi clue di atas:
           */
        }

}



//Jangan lupa untuk masukan paramter yang sesuai dengan fungsi yang dibugat
//Fugsi untuk print data yang terdapat pada linked list
void printList(struct node * head, struct node * tail, struct node * temp){
    //Mudah kok, tidak perlu hint lagi jika fungsi insertNode() sudah bisa dan paham
    //Ingat strukturnya : head-> node1 -> node2 -> .... -> node(n) -> NULL
    
    //Masukan code untuk inisiasi awal, jadikan temp kembali ke address node1

    /*
    clue: 
    - Lakukanlah print data pada node temp, kemudian temp akan berpindah ke node selanjutnya
    - Ketika temp bernilai NULL, maka berarti sudah mencapai node terakhir
    Masukan code untuk memenuhi clue di atas:
    */

}


void removeList(struct node * head, struct node * tail, struct node * temp, int n){
    //Masukan code untuk inisiasi awal, jadikan temp kembali ke address node1


    /*
    Mulailah iterasi, kemudian, saat menemukan node yang memiliki data yang sama dengan data yang ingin dihapus, maka hapuslah node tersebut
    Clue:
    Contoh, misal ingin menghapus node 3:
    head -> node1 -> node2 -> node3 -> node4 -> node5 -> NULL
    Langkah 1:
    jadikan next dari node2 ke node4
    head -> node1 -> node2 -> node4 -> node5 -> NULL     node3 masih ada, namun tidak terhubung dengan node2
    Langkah 2:
    Hapus node3, anda bisa menggunakan free()
    */
}
