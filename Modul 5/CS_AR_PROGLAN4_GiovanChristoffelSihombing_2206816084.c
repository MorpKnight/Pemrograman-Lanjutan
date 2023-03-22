#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

void delay(){
    int ms = 1000 * 0.01;
    clock_t start_time = clock();
    while(clock()<start_time+ms);
}

int binary_search(int *arr, int x, int low, int high){
    int mid;
    while(low <= high){
        delay();
        mid = low + (high-low)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] < x){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linear_search(int *arr, int x){
    int i;
    for(i = 0; i < 500; i++){
        delay();
        if(arr[i] == x){
            return i;
        }
    }

    return -1;
}

void check_time(){
    int data[500] = {1,5,7,11,13,14,15,15,17,17,17,18,18,19,21,21,23,23,26,29,29,30,30,33,35,37,38,44,47,48,49,50,51,53,56,57,59,61,62,63,63,65,67,67,67,72,73,77,79,79,84,88,88,90,90,91,91,92,93,94,98,100,101,102,104,104,104,105,107,111,111,112,114,114,114,120,121,122,122,125,126,126,127,139,140,143,143,144,151,151,153,154,157,157,158,158,159,161,162,163,167,167,167,168,170,179,181,184,189,192,193,194,194,195,196,196,196,201,206,210,212,214,215,218,218,219,220,221,224,229,232,237,240,242,243,247,247,255,255,257,259,260,262,264,264,265,267,268,268,272,275,277,278,280,287,293,294,295,297,301,302,303,311,312,313,314,317,321,321,322,322,323,326,334,334,335,335,337,338,340,340,342,344,346,347,347,347,349,349,354,355,359,363,363,366,367,372,373,373,374,374,375,378,379,382,384,384,387,388,390,390,394,395,396,399,400,403,406,407,408,408,410,412,424,425,426,428,429,431,436,436,439,443,444,445,445,447,448,449,450,451,451,452,455,458,462,467,472,474,484,485,490,490,493,495,497,500,501,501,503,503,508,511,511,517,518,524,526,526,527,530,531,531,532,538,541,542,544,544,545,546,547,550,559,559,560,563,564,564,567,568,569,570,572,572,573,573,579,580,585,585,588,590,590,593,594,596,597,598,598,600,600,601,602,604,604,604,605,607,610,614,614,615,620,622,625,626,627,628,629,632,637,640,640,642,648,648,653,655,655,656,663,668,671,674,678,681,683,684,685,688,690,692,693,694,695,700,700,702,708,708,712,714,716,723,724,727,731,732,733,734,734,735,735,736,740,741,742,742,743,747,750,751,752,756,756,759,761,763,764,765,765,766,767,771,772,772,773,776,777,779,782,790,790,793,801,802,804,808,808,808,809,810,811,812,816,817,819,827,828,831,833,834,836,836,841,843,844,845,848,852,854,854,855,857,857,859,860,860,861,865,874,875,876,885,886,888,889,891,892,895,896,897,900,903,914,914,915,915,915,916,916,918,920,920,923,925,928,929,929,933,935,936,938,938,939,942,943,945,947,950,951,958,963,966,967,968,969,970,972,972,979,986,987,987,988,988,990,990,997};
    int linear, binary_res, find_number;
    double exe_time;
    clock_t start, end;

    printf("Masukan angka: ");
    scanf("%d", &find_number);
    
    printf("=========== LINEAR SEARCH ===========\n");
    start = clock();
    linear = linear_search(data, find_number);
    end = clock();
    if(linear == -1){
        printf("Angka yang dicari tidak ditemukan\n");
    } else {
        printf("Angka yang dicari berada pada indeks ke-%d\n", linear);
    }
    exe_time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Execution time: %f\n", exe_time);

    printf("\n\n=========== BINARY SEARCH ===========\n");
    start = clock();
    binary_res = binary_search(data, find_number, 0, 499);
    end = clock();
    if(binary_res == -1){
        printf("Angka yang dicari tidak ditemukan\n");
    } else {
        printf("Angka yang dicari berada pada indeks ke-%d\n", binary_res);
    }
    exe_time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Execution time: %f\n", exe_time);

}

void find_sum_char(){
    char sen[100], letter;
    int i, count;

    count = 0;

    printf("Masukan kalimat: ");
    scanf("\n");
    fgets(sen, 100, stdin);

    for(i = 0; i < 100; i++){
        sen[i] = tolower(sen[i]);
    }
    printf("Huruf yang akan dihitung: ");
    scanf("%c", &letter);
    for(i = 0; i < strlen(sen); i++){
        if(sen[i] == letter){
            count += 1;
        }
    }

    printf("Jumlah %c pada kalimat: %d\n", letter, count);
}

int main(){
    int mode;

    menu:
        printf("Menu:\n1. Soal 1\n2. Soal 2\n3. Keluar program\n");
        printf("Masukan menu: ");
        scanf("%d", &mode);

        switch(mode){
            case 1:
                find_sum_char();
                printf("\n");
                goto menu;
                break;
            case 2:
                check_time();
                printf("\n");
                goto menu;
                break;
            case 3:
                printf("Keluar dari program..");
                exit(0);
                break;
            default:
                printf("Masukan angka yang benar woe!\n");
                goto menu;
                break;
        }

    return 0;
}


