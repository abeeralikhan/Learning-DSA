#include <iostream>

using namespace std;

int* Merge (int A[], int B[], int m, int n) {

    int i = 0, j = 0, k = 0, size = m+n; 
    int *C = new int[size];

    while (k < size) {
        if(A[i]<B[j]) {
            C[k] = A[i];
            i++;
            k++;
        } else {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    return C;
}

int main() {
    int A[4] = {0, 1, 5, 7};
    int B[4] = {2, 6, 8, 69};
    int *C;

    C = Merge(A, B, 4, 4);

    for (int i = 0; i < 8; i++)
        cout << C[i] << endl;

    delete[] C;
    return 0;
}