#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    int A, B;
    int* arr = NULL;

    while (1) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0) {
            break;
        }
        count++;
        arr = (int*)realloc(arr, sizeof(int) * count);

        arr[count - 1] = A + B;
    }
    
    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}