# include <iostream>
# include <algorithm>
# include <string>
using namespace std;



int main () {
    string input1, input2;
    cin >> input1 >> input2;

    reverse(input1.begin(), input1.end());
    reverse(input2.begin(), input2.end());

    if (input1 > input2) {
        cout << input1;
    } else {
        cout << input2;
    }
    return 0;
}