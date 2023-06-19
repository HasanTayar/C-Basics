#include <stdio.h>
#include <string.h>

#define SIZE 100
#define ROWS 3

int main() {
    char matrix[ROWS][SIZE];
    char str[SIZE];
    int count = 0;

    for(int i = 0; i < ROWS; i++) {
        fgets(matrix[i], SIZE, stdin);
        matrix[i][strcspn(matrix[i], "\n")] = 0;
    }

    fgets(str, SIZE, stdin);
    str[strcspn(str, "\n")] = 0;

    for(int i = 0; i < ROWS; i++) {
        if(strcmp(matrix[i], str) == 0) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
