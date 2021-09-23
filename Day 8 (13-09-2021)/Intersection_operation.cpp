#include <iostream>

using namespace std;

int* IntersectionUnsorted(int A[], int B[], int m, int n) {

    int *C = new int[m+n];
    int k = 0; // Length variable for Set C;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i]==B[j]) { // Comparing elements of Set A and B, if they're same, insert into the Set C, break the loop, and increment the k pointer
                C[k] = A[i];
                k++;
                break;
            }
        }
    }

    return C;
}

// For sorted arrays --> O(n)
// Using Merge technique for sorted arrays 
int* IntersectionSorted(int A[], int B[], int m, int n) {

    int i = 0, j = 0, k = 0; 
    int *C = new int[m+n];

    while (i < m && j < n) {
        if(A[i]<B[j]) {
            i++;

        } else if (A[i]==B[j]) {
            C[k] = A[i];
            i++;
            j++;
            k++;

        } else {
            j++;
        }
    }

    return C;
}


int main() {
    int A[5] = {4, 5, 6, 10, 12};
    int B[5] = {2, 4, 5, 7, 12};
    int *C;

    C = IntersectionSorted(A, B, 5, 5);

    for (int i = 0; i < 3; i++)
        cout << C[i] << endl;

    delete[] C;
    return 0;
} 