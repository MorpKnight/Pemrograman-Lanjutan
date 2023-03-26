#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct database{
	char name[100];
    char initial[50];
} Name;

void sortName(Name *Data, int count) {
    // Sort names in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(Data[i].name, Data[j].name) > 0) {
                // Swap names
                char temp[100];
                strcpy(temp, Data[i].name);
                strcpy(Data[i].name, Data[j].name);
                strcpy(Data[j].name, temp);
            }
        }
    }

    // Build a function/algorithm to create initials
    
}

int main() {
    Name Data[100]; // assuming max count is 100
    int count = 0;

    // Read input names from 
    // Sort names and create initials

    // Print sorted names and searching result
    return 0;
}
