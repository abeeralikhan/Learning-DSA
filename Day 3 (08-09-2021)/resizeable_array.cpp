#include <iostream>

using namespace std;

void increaseArraySize(int p[], int oldSize, int newSize) {
    // Creating an array of larger size
    int *q = new int[newSize];

    // Copying all the elements from old array to new array
    for(int i = 0; i < oldSize; i++)
        q[i+1] = p[i];

    // Deallocating old array
    delete[] p;

    // Making old pointer to point at the new array's pointer
    p = q;

    // Making newly created pointer null, so there won't be two pointers pointing at the same array
    q = NULL;
}

int main() {
    // Defining size of the array
    int size = 4;

    // Allocating an array dynamically in the memory 
    int *p = new int[size];

    // Populating the array
    p[0] = 5;
    p[1] = 3;
    p[2] = 1;
    p[3] = 9;
    // Printing all elements of this array
    for(int i = 0; i < size; i++)
        cout << p[i] << ' ';

    cout << endl << *p << endl;
    // Increasing it's size
    increaseArraySize(p, size, 10);

    // Printing all elements of this array
    //for(int i = 0; i < 20; i++)
        //cout << p[i] << ' ';

    cout << *p << endl;
    
}