#include <iostream>

using namespace std;

int fact_recur(int n) {
    if (n < 2) {
        return 1;
    } 
    return n * fact_recur(n - 1);
}

int fact_loop(int n) {
    int j = n;
    if (n < 2) {
        return 1;
    }
    for(int i = 1; i < (n - 1) ; i++) {
        j *= (n - i);
    }

    return j;
}

int main() {
    cout << fact_loop(4);
    return 0;
}