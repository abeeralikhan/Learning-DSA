#include <iostream>

using namespace std;

void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n-1);
        cout << n << endl;
    }
}

void usingLoop(int n) {
    int i = 0;
    while(n > 0) {
        cout << n - ((n - i) - 1) << endl;
        n--;
        i++;
    }

}

void treeRecursion(int n) {
    if (n > 0) {
        cout << n << endl;
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}

int main() {
    int n = 4;
    treeRecursion(n);
    //usingLoop(n);
    return 0;
}