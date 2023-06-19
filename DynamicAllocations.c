#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    int count;
} CharCount;

CharCount* countChars(const char* str, int* uniqueCharCount) {
    *uniqueCharCount = 0;
    int counts[256] = {0};

    for (int i = 0; i < strlen(str); ++i)
        counts[(unsigned char)str[i]]++;

    for (int i = 0; i < 256; ++i)
        if (counts[i] > 0)
            (*uniqueCharCount)++;

    CharCount* arr = malloc((*uniqueCharCount) * sizeof(CharCount));
    int j = 0;

    for (int i = 0; i < 256; ++i)
        if (counts[i] > 0) {
            arr[j].c = (char)i;
            arr[j].count = counts[i];
            j++;
        }

    return arr;
}

int main() {
    const char* str = "xbxdcc";
    int uniqueCharCount;

    CharCount* arr = countChars(str, &uniqueCharCount);
    printf("Unique characters: %d\n", uniqueCharCount);

    for (int i = 0; i < uniqueCharCount; ++i)
        printf("%c appears %d time(s)\n", arr[i].c, arr[i].count);

    free(arr);
    return 0;
}
