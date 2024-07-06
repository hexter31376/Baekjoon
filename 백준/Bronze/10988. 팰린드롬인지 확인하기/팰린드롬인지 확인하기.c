#include <stdio.h>
#include <string.h>

int main () {
    char input[101];
    scanf("%100s", input);

    int result = 1;

    int n = strlen(input);
    for (int frontCursor = 0; frontCursor < (n / 2); frontCursor++) {
        int lastCursor = (n - 1 - frontCursor);
        if (input[frontCursor] != input[lastCursor]) {
            result = 0;
        }
    }

    printf("%d", result);
    return 0;
}