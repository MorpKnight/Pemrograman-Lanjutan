#include <stdio.h>

int main(){
    int n, i, j, indexMin, arr[] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
    n = sizeof(arr)/sizeof(arr[0]);
    
    indexMin = 0;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[indexMin]){
                indexMin = j;
            }
        }
        if(indexMin != i){
            int temp = arr[i];
            arr[i] = arr[indexMin];	
            arr[indexMin] = temp;
        }
    }

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
