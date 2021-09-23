#include <iostream>

using namespace std;

// For sorted arrays --> O(n)
// Using Merge technique for sorted arrays 
int* UnionSorted(int A[], int B[], int m, int n) {

    int i = 0, j = 0, k = 0; 
    int *C = new int[m+n];

    while (i < m && j < n) {
        if(A[i]<B[j]) {
            C[k] = A[i];
            i++;
            k++;

        // If we encounter same elements, we would just copy only one and increment both the pointers
        } else if (A[i]==B[j]) {
            C[k] = A[i];
            i++;
            j++;
            k++;

        } else {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    return C;
}

int* UnionUnsorted(int A[], int B[], int m, int n) {

    int *C = new int[m+n];
    int k = 0; // Length variable for Set C;

    // Step 01: Copy all the elements of Set A into the Set B, and simulateniously increment its pointer;
    for (int i = 0; i < m; i++) {
        C[i] = A[i];
        k++;
    }
    bool foundDuplicate = false;
    for (int i = 0; i < n; i++) { // n representing no. of elements of Set B
        for (int j = 0; j < m; j++) { // m representing no. of elements of Set A

            if (B[i] == C[j]) { // Duplicacy has found, A and B had a shared element, skipping it
                foundDuplicate = true;
                break;
            }  
        }

        if (!foundDuplicate) { // Didnt find any duplicacy, hence append the element to set C
            C[k] = B[i];
            k++;
        }

        foundDuplicate = false; // turning it back to false once triggered 
    }

    return C;
}


int main() {
    int A[5] = {3, 5, 10, 4, 6};
    int B[5] = {12, 4, 7, 2, 5};
    int *C;

    C = UnionUnsorted(A, B, 5, 5);

    for (int i = 0; i < 10; i++)
        cout << C[i] << endl;

    delete[] C;
    return 0;
}