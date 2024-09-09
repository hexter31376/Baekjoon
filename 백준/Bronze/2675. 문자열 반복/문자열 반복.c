# include <stdio.h>
# include <string.h>

int main (void) {
    int testCount;

    scanf("%d", &testCount);
    fflush(stdin);

    for (int i = 0; i < testCount; i++) {
        int reapetCount;
        char inputEachCaseString[21];

        scanf("%d %s", &reapetCount, inputEachCaseString);
        for (int i = 0; inputEachCaseString[i] != '\0'; i++) {
            for (int j = 0; j < reapetCount; j++) {
                printf("%c",inputEachCaseString[i]);
            }
        }
        printf("\n");
    }

    return 0;
}