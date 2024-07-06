#include <stdio.h>
#include <string.h>

int main () {
    char input[101];
    scanf("%100s", input);

    int n = strlen(input);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (input[i] == 'c') {
            if (input[i + 1] == '=' ||  input[i + 1] == '-' && i <= n - 1) {
                i++;
            }
        } else if (input[i] == 'd') {
            if (input[i + 1] == 'z' && i <= n - 1) {
                if (input[i + 2] == '=' && i <= n - 2) {
                    i += 2;
                }
            } else if (input[i + 1] == '-' && i <= n - 1){
                i++;
            }
        } else if (input[i] == 'l') {
            if (input[i + 1] == 'j' && i <= n - 1) {
                i++;
            }
        } else if (input[i] == 'n') {
            if (input[i + 1] == 'j' && i <= n - 1) {
                i++;
            }
        } else if (input[i] == 's') {
            if (input[i + 1] == '=' && i <= n - 1) {
                i++;
            }
        } else if (input[i] == 'z') {
            if (input[i + 1] == '=' && i <= n - 1) {
                i++;
            }
        }
        count++;
    }
    printf("%d", count);
    return 0;
}