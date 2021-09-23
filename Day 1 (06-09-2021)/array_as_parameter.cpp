#include <iostream>

using namespace std;

void changeIndex(int* A, int index, int value) {
    A[index] = value;
}

void printArray(int A[], int size) {
    for(int x = 0; x < size; x++) {
        cout << A[x] << endl;
    }
}

int main() {
    // We can change the value of an array from another function.
    int arr[3] = {1, 2, 3};
    printArray(arr, 3);
    changeIndex(arr, 1, 9);
    printArray(arr, 3);    
    return 0;
}