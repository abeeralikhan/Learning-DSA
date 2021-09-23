#include <iostream>
using namespace std;

void printInReverse(int x) {
    if(x > 0) {
        cout << x << endl;
        printInReverse(x-1);
    }
}

void printSeries(int x) {
    if(x > 0) {
        printSeries(x-1);
        cout << x << endl;
    }
}

int main() {
    int x = 5;
    printSeries(x);
    printInReverse(x);
    return 0;
}