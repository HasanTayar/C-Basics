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
    char text[ROWS][SIZE];
    char temp[SIZE];

    for(int i = 0; i < ROWS; i++) {
        fgets(text[i], SIZE, stdin);
        text[i][strcspn(text[i], "\n")] = 0;
    }

    strcpy(temp, text[0]);
    for(int i = 0; i < ROWS - 1; i++) {
        strcpy(text[i], text[i + 1]);
    }
    strcpy(text[ROWS - 1], temp);

    print_matrix(text);

    return 0;
}
