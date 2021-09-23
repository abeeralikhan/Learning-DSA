#include <iostream>
#include <string>
using namespace std;

int main() {
    int A[] = {1, 2, 3, 4, 5, 6};
    string S[] = {"Abeer", "Zubair", "Jahangir"};
    int Zeros[5];
    int tryZero[5] = {1, 2};

    for(int x:A) {
        cout << x << endl;
    }

    for(string x:S) {
        cout << x << endl;
    }

    for(int i: Zeros) {
        cout << i << endl;
    }

    for(int i:tryZero) {
        cout << i << endl;
    }

    return 0;
}