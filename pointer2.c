#include <stdio.h>

#define N 5
#define M 4

void print_arr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[N][M];
    int *ptr[N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = i * M + j;
        }
        ptr[i] = arr[i];
    }

    for(int i = 0; i < N; i++) {
        print_arr(ptr[i], M);
    }

    return 0;
}
