#include <stdio.h>

#define N 5
#define M 4

// Function to take inputs using only pointers
void input(int *arr, int size) {
    int *end = arr + size;
    while (arr < end) {
        scanf("%d", arr++);
    }
}

// Function to print array from end to beginning using only pointers
void reverse_printer(int *arr, int size) {
    int *start = arr - 1;
    arr = arr + size - 1;
    while (arr > start) {
        printf("%d,", *arr--);
    }
}

// Main function
void main() {
    int arr[N][M];
    int half = N * M / 2;

    for (int i = 0; i < N; i++) {
        input(*(arr + i), M);
    }

    reverse_printer(*arr, half);

    reverse_printer(*arr + half, half);
}
