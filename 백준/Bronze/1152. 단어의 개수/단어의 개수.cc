#include <iostream>
#include <string>
using namespace std;

int main () {
    char word;
    int count = 0;
    bool iWordFlag = false;

    for (;;){
        word = cin.get();

        if (word == '\n') {
            break;
        } else if (iWordFlag == false && word != ' ') {
            iWordFlag = true;
            count++;
        } else if (iWordFlag == true && word != ' ') {
            continue;
        } else if (word == ' ') {
            iWordFlag = false;
        }
    }
    cout << count;
    return 0;
}