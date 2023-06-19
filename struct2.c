#include <stdio.h>

typedef struct {
    char character;
    int count;
} Appear;

void countCharacters(char* str, Appear* arr) {
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            arr[str[i] - 'A'].count++;
        }
        i++;
    }
}

int main() {
    char str[100];
    Appear arr[26];

    for(int i = 0; i < 26; i++) {
        arr[i].character = 'A' + i;
        arr[i].count = 0;
    }

    printf("Enter a string:\n");
    fgets(str, 100, stdin);

    countCharacters(str, arr);

    for(int i = 0; i < 26; i++) {
        printf("%c: %d\n", arr[i].character, arr[i].count);
    }

    return 0;
}
