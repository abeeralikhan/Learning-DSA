#include <iostream>

using namespace std;

int main() {
    int A[4][5] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15},
                   {26, 27, 28, 29, 30}};

    // Access element 10 through arr arithmetic
    cout << A + 1 << endl; // Address of 2nd pointer, pointing at row 2
    cout << *(A + 1) << endl; // Base address of row 2 aka the address which pointer 2 is pointing at
    cout << *(A + 1) + 4 << endl; // Address of 5th element of row 2
    cout << *(*(A + 1) + 4) << endl; // Value of 5th element of row 2 




    return 0;
}