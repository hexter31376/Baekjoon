#include <stdio.h>

int main() {
    int input;
    int tmp[6] = {0};

    for (int i = 0; i < 3; i++) {
        scanf("%d", &input);
        tmp[input - 1]++;
    }

    int same = 0;
    int* tmpp = NULL;

    for (int i = 0; i < 6; i++) {
        if (same <= tmp[i]) {
            same = tmp[i];
            tmpp = &tmp[i];
        }
    }
    int result = tmpp - tmp + 1;

    int price = 0;
    switch (same) {
        case 1:
            price = result * 100;
            break;
        case 2:
            price = result * 100 + 1000;
            break;
        case 3:
            price = result * 1000 + 10000;
            break;
        default:
            price = 0;
            break;
    }

    printf("%d", price);
    return 0;
}