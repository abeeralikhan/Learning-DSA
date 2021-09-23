#include <iostream>

using namespace std;

int power(int n, int m) {
    if (n < 1) {
        return 1;
    }
    if (m > 0) {
        return n * power(n, m-1);
    }

    return 1;
}
int main() {
    cout << power(4, 2);
    return 0;
}