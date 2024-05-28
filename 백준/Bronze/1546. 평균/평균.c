#include <stdio.h> // 표준 입출력 헤더파일

double get_max (double arr[], int N) {
    double max = 0;

    for(int i = 0; i < N; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

double change_average (double arr[], int N) {
    double max = get_max(arr, N);

    double average = 0;

    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] / max * 100;
        average += arr[i];
    }

    return average /= N;
}

int main () {
    int N;
    scanf("%d", &N);

    double arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }

    printf("%lf", change_average(arr, N));
    return 0;
}