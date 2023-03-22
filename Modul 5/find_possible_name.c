#include <string.h>
#include <stdio.h>

void find_name(char list_name[][100], int len_list_name, char *keyword){
    int i;
    printf("Kemungkinan nama yang Anda maksud:\n");
    for(i = 0; i < len_list_name; i++){
        if(strstr(list_name[i], keyword) != NULL){
            printf("%s\n", list_name[i]);
        }
    }
}

int main(){
    char keyword[100];
    int len_list, i;

    printf("Masukan jumlah nama: ");
    scanf("%d", &len_list);

    char list_name[len_list][100];
    for(i = 0; i < len_list; i++){
        printf("Masukan nama ke-%d: ", i+1);
        scanf("%s", &list_name[i]);
    }

    do {
        printf("Masukan nama yang ingin dicari: ");
        scanf("%s", &keyword);
        find_name(list_name, len_list, keyword);
    } while(strcmp(keyword, "exit") != 0);

    return 0;
}