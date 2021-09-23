#include <iostream>

using namespace std;

int SingleMissingElement(int A[], int n) {
    for (int i = 0; i < (n-1); i++) {
        if (A[i+1]-A[i]!=1) {
            return A[i]+1;
        }
    }

    return -1;
}

int main() {
    int A[11] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};

    cout << "The missing element is " << SingleMissingElement(A, 11) << endl;
    return 0;
}