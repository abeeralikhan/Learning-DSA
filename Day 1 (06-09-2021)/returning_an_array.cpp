#include <iostream>

using namespace std;

int* createSparseArray(int size) {
    int* arr;
    arr = new int[size];

    for(int i = 0; i < size; i++){
        arr[i] = i%2==0 ? i : 1;
    }

    return arr;
}

void printArray(int* A, int size) {
    for(int x = 0; x < size; x++) {
        cout << A[x] << endl;
    }
}

int main() {
    int *arr, size = 10;
    arr = createSparseArray(size);
    printArray(arr, size);

    delete arr;
    return 0;
}