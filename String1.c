#include <stdio.h>
#include <string.h>

#define SIZE 100
#define ROWS 3

void print_matrix(char matrix[ROWS][SIZE]) {
    for(int i = 0; i < ROWS; i++) {
        printf("%s\n", matrix[i]);
    }
}

int main() {
    char text1[ROWS][SIZE];
    char text2[ROWS][SIZE];
    char text3[ROWS][SIZE] = {0};

    for(int i = 0; i < ROWS; i++) {
        fgets(text1[i], SIZE, stdin);
        text1[i][strcspn(text1[i], "\n")] = 0;
        fgets(text2[i], SIZE, stdin);
        text2[i][strcspn(text2[i], "\n")] = 0;
    }

    for(int i = 0; i < ROWS; i++) {
        if(strlen(text1[i]) + strlen(text2[i]) < SIZE) {
            strcpy(text3[i], text1[i]);
            strcat(text3[i], text2[i]);
        } else {
            text3[i][0] = '\0';
        }
    }

    print_matrix(text3);

    return 0;
}
