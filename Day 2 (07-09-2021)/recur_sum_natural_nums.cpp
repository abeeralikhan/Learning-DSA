#include <iostream>

using namespace std;

int sumNaturalNumbers(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return x + sumNaturalNumbers(n-1);
    }
    return 0; // At the end of recursion, the value of x will remain same from bottom to up
}

int main() {
    int n = 4;
    int sum = sumNaturalNumbers(n);
    cout << sum << endl;
    return 0;
}

