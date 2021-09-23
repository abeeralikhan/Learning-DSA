#include <iostream>

using namespace std;

struct Array {
    int *A, size, length = 0;
};

void init_array(Array *arr, int size) {
    arr->A = new int[size];
    arr->size = size;
}

void display(Array arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr.A[i] << endl;
}

int main() {
    Array *arr;

    arr = new Array;
    int size = 5;
    init_array(arr, size);

    for (int i = 0; i < size; i++)
        arr->A[i] = i+1;

    display(*arr, size);

    delete arr;
    delete[] arr->A;
    return 0;
}