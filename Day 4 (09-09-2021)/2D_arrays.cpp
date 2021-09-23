#include <iostream>

using namespace std;

// For dynamically generated arrays
void print2d(int **A, int row, int col) {

    for(int i = 0; i < row; i++) {

        for(int j = 0; j < col; j++) {

            cout << A[i][j] << " ";

        }
        cout << endl;
    }
}

// For normall arrays 
// While passing 2D array to a function make sure to mention no. of cols (no. of rows arent not necessary to mention)
void print2d_(int A[][2], int row, int col) {

    for(int i = 0; i < row; i++) {

        for(int j = 0; j < col; j++) {

            cout << A[i][j] << " ";

        }
        cout << endl;
    }
}

int main() {
    // There are two ways to declare a 2D array;
    // 1. Normal Declaration (everything is in stack memory)
    int B[3][2] = {{1, 2}, {4, 5}, {7, 8}};
    print2d_(B, 3, 2);
    int C[3][3] = {};

    // 2. Declaration through array of pointers (pointers are in stack, whereas arrays are in heap)

    // Step 1: Declare an array of three pointers of type int

    int *arr_ptrs[3]; // This is also a pointer of pointers, but its in stack. 

    // Step 2: Point a new array with each pointer

    arr_ptrs[0] = new int[3];
    arr_ptrs[1] = new int[3];
    arr_ptrs[2] = new int[3];

    // Step 3: Now populate this type array like you normally use to those

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr_ptrs[i][j] = i*j;
        }
    }

    print2d(arr_ptrs, 3, 3);

    // 3. Declaring a pointer of pointers, those pointers are in heap, eventually pointing at arrays
    // those are in heap as well (everything is in heap memory)
    
    // Step 1: Declarign a pointer, which will point at the pointers (that's why '**' is used)
    int **ptr_of_ptrs;

    // Step 2: Now, dynamically init an array of pointers, and point this pointer at those pointers
    
    ptr_of_ptrs = new int *[3]; // Here, '*' represents this dynammic array holds pointers

    // Step 3: Now, one by one, point those pointers to their own d_init arrays

    for (int i = 0; i < 3; i++)
        ptr_of_ptrs[i] = new int[4];

    // Above 3 steps will create an array of 3x4 

    // Step 4: Now, populate this array

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ptr_of_ptrs[i][j] = i*j;
        }
    }

    print2d(ptr_of_ptrs, 3, 4);

    delete[] arr_ptrs;
    delete[] ptr_of_ptrs;

    return 0;
}