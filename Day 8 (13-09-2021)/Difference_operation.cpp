#include <iostream>

using namespace std;

// Unsorted Arrays --> O(n^2)
int* DifferenceUnsorted(int A[], int B[], int m, int n) {

    int *C = new int[m+n];
    int k = 0; // Length variable for Set C;
    
    bool foundDuplicate = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i]==B[j]) { // Comparing elements of Set A and B, if they're same, dont insert into the Set C, break the loop, and increment the k pointer
                foundDuplicate = true;
                break;
            }
        }

        if (!foundDuplicate) {
            C[k] = A[i];
            k++;
        }

        foundDuplicate = false;
    }

    return C;
}

// For sorted arrays --> O(n)
// Using Merge technique for sorted arrays 
int* DifferenceSorted(int A[], int B[], int m, int n) {

    int i = 0, j = 0, k = 0; 
    int *C = new int[m+n];

    while (i < m && j < n) {
        if(A[i]<B[j]) { // Increment and copy values represting on i 
            C[k] = A[i]; // We care about values of A, not B in difference operation. (A - B)
            k++;
            i++;

        } else if (A[i]==B[j]) { // Same elements, dont need!
            i++; // When elements are same, we dont want to copy it from either one of the sets
            j++; // Just increment the pointers without copying anything into the set C

        } else { // Just increment j++ 
                // We dont care about values of Set B in difference operation, so won't copy it 
            j++;
        }
    }

    return C;
}


int main() {
    int A[5] = {2, 5, 6, 10, 12};
    int B[5] = {2, 4, 5, 7, 12};
    int *C;

    C = DifferenceSorted(A, B, 5, 5);

    for (int i = 0; i < 2; i++)
        cout << C[i] << endl;

    delete[] C;
    return 0;
} 