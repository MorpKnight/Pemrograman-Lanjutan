#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 99999

int main(){
    int graphMatrix[8][8] = {
        {0, 5, 0, 6, 0, 4, 0, 7},
        {5, 0, 2, 4, 3, 0, 0, 0},
        {0, 2, 0, 1, 0, 0, 0, 0},
        {6, 4, 1, 0, 7, 0, 0, 0},
        {0, 3, 0, 7, 0, 0, 6, 4},
        {4, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 6, 3, 0, 2},
        {7, 0, 0, 0, 4, 0, 2, 0}
    };

    // find shortest path
    int shortestPath[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            shortestPath[i][j] = INT_MAX;
        }
    }

    for(int k = 0; k < 8; k++){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(shortestPath[i][k] + shortestPath[k][j] < shortestPath[i][j]){
                    shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];
                }
            }
        }
    }

    // print shortest path
    printf("Shortest path:\n");
    for(int i = 0; i < 8; i++){
        printf("Node %d: ", i + 1);
        for(int j = 0; j < 8; j++){
            if(shortestPath[i][j] != INT_MAX){
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }

    return 0;
}
