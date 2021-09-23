#include <iostream>

using namespace std;

int fact(int n) {
    int j = n;
    if (n < 2) {
        return 1;
    }
    for(int i = 1; i < (n - 1) ; i++) {
        j *= (n - i);
    }
    return j;
}

float pow(float n, float m) {
    float result = n;

    if (m < 1) {
        return 1;
    }

    for (int i = 1; i < m; i++) {
        result*=n;
    }

    return result;
}

float taylor_series(float x, int n) {
    if (n < 1) {
        return 1;
    }

    return (pow(x, n) / fact(n)) + taylor_series(x, n - 1);
}
 
int main() {
    cout << taylor_series(4, 10);
    return 0;
}