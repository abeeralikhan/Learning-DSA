#include <iostream>
#include <cmath>

using namespace std;

class Array {
    int *A, size, length = 0;

    bool isFull();
    bool isEmpty();
    void swap(int, int);

    public:
        Array(int size) {
            A = new int[size];
            this->size = size;
        }

        ~Array() {
            delete[] A;
        }

        void add(int x) {
            if (isFull()) {
            } else {
                A[length] = x;
                length++;
                cout << x << " has been added!" << endl;
            }
        }

        void display() {
            for (int i = 0; i < length; i++) 
                cout << A[i] << endl;
        }

        void insert(int x, int index) {
            if (isFull()) {
                cout << "Array is full!" << endl;
            } else {
                if (index == length) {
                    add(x);
                } else {
                    for (int i = length; i >= index; i--) {
                        A[i] = A[i-1];
                    }
                    A[index] = x;
                    length++;
                    cout << x << " has been inserted at index " << index << endl; 
                }
            }
        }

        void deleteByIndex(int index) {
            if (index < length) {
                int x = A[index];
                if (index == (length - 1)) {
                    length--;
                } else {
                    for (int i = index; i < length-1; i++) {
                    A[i] = A[i+1];
                }
                length--;
                }
                cout << x << " has been deleted from the array!" << endl;
            } else {
                cout << "Index out of range!" << endl;
            }
        }

        int linearSearch(int key) {
            for (int i = 0; i < length; i++) {
                if (A[i] == key) {
                    return i;
                }
            }
            return -1;
        }

        int lSearch1(int key) { 
            // This function is implementing the "Transposition" strategy while searching
            // for an element in the array
            // In which, searched element will be decremented
            for (int i = 0; i < length; i++) {
                if (A[i] == key) {
                    if (i!=0) {
                        swap(i, i-1);
                        return i-1;
                    } 
                    return i;
                }
            }
            return -1;
        }

        int lSearch2(int key) {
            // This function is implementing the "Move to front" strategy while searching
            // for an element in the array
            // In which, searched element will be swapped with 0th index elemenent
            for (int i = 0; i < length; i++) {
                if (A[i] == key) {
                    if (i!=0) {
                        swap(i, 0);
                        return 0;
                    } 
                    return i;
                }
            }
            return -1;
        }

        int BinarySearch(int key) {
            // Array must be sorted
            int l = 0, r = length - 1, mid;

            while(l <= r) {
                mid = (l+r)/2;
                if (A[mid] == key) {
                    return mid;

                } else if(A[mid] < key) {
                    l = mid + 1; // m + 1
                } else {
                    r = mid - 1; // m - 1
                }
            }

            return -1;
        }

        int Get(int index) {
            if ((index >= 0) && (index < length)) {
                return A[index];
            }

            return -1;
        }

        void Set(int index, int x) {
            if ((index >= 0) && (index < length)) {
                A[index] = x;
            } else {
                cout << "Index out of range!" << endl;
            }
        }

        int GetSize() {
            return length;
        }

        int Sum() {
            if (!isEmpty()){
                int sum = 0;
                for (int i = 0; i < length; i++)
                    sum+=A[i];

                return sum;
            }
            return -1;  
        }

        double Average() {
            if (!isEmpty()) {
                return Sum()/GetSize(); 
            }

            return -1;
        }

        int Max() {
            if (!isEmpty()) {
                int max = A[0];
                for(int i = 1; i < length; i++)
                    if (A[i] >= max)
                        max = A[i];

                return max;
            }

            return -1;  
        }

        int Min() {
            if (!isEmpty()) {
                int min = A[0];
                for(int i = 1; i < length; i++)
                    if (A[i] <= min)
                        min = A[i];

            return min;
            }

            return -1;  
        }

        void Reverse1() {
            // This reverse function will copy all the elements into an auxilary array in reverse order
            // Then, all the elements will be copied back into the main array in sequential order

            if(!isEmpty()) {
                int B[length];
                for (int i = (length-1), j = 0; i > -1; i--, j++)
                    B[j] = A[i];

                for (int i = 0; i < length; i++)
                    A[i] = B[i];

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void Reverse2() {
            // This reverse function will swap mirror elements with each other
            // Original Idea (Alhumdulillah)

            if(!isEmpty()) {
                for (int i = 0, j = (length-1); i <= j; i++, j--) {
                    swap(i, j); // FIXED: I was passing A[i] & A[j] here instead of just i and j 
                }

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void LeftShift() {
            if(!isEmpty()) {
                for (int i = 0; i < (length-1); i++) // i starting from 0, and ending on length-1
                    A[i] = A[i+1]; // All elements are shifting to the left side

                A[length-1] = 0; // Making last element to be zero

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void RightShift() {
            if(!isEmpty()) {
                for (int i = (length - 1); i > 0; i--) // i starting from length, and ending on 1
                    A[i] = A[i-1]; // All element are shifting to the right side

                A[0] = 0; // Making first element to be zero

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void LeftRotate() {
            if(!isEmpty()) {
                int firstElement = A[0];
                for (int i = 0; i < (length-1); i++)
                    A[i] = A[i+1];

                A[length-1] = firstElement;

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void RightRotate() {
            if(!isEmpty()) {
                int lastElement = A[length-1];
                for (int i = (length-1); i > 0; i--)
                    A[i] = A[i-1];

                A[0] = lastElement;

            } else {
                cout << "There are not enough elements in the array!" << endl;
            }
        }

        void Insert_sorted(int x) {
            // Through this function a sorted array wil be maintained
            // We we'll compare x with every element, if the compared element is great, then x will be inserted at
            // that index

            if (!isFull()) {
                bool inserted = false;
                for (int i = 0; i < length; i++) {
                    if (x < A[i]) {
                        insert(x, i);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) // If all elements are smaller then the passed element. Then, it must be placed in the end manually
                    insert(x, GetSize());
            } else {
                cout << "Array doesnt have any space!" << endl;
            }
        }

        bool isSorted() {
            if (!isEmpty()) {
                for (int i = 0; i < (length-1); i++) {
                    if (A[i] > A[i+1]) {
                        return false; // Found unsorted pair of elements; returning false;
                    }
                }
                return true; // Array is sorted; returning true;

            } else {
                return false; // Array is empty; returning false;
            }
        }

        void MoveNegatives() {
            if (!isEmpty()) {
                int i = 0, j = length - 1;

                while(j > i) {
                    while(A[i] < 0) {i++;};
                    while(A[j] >= 0) {j--;}; // Fixed: Wrote j++ instead of j-- initially 
                    if (j > i){
                        swap(i, j);
                    }
                }
            } else {
                cout << "Array is empty!" << endl;
            }
        }
};

bool Array::isFull() {
    return size == length;
}

bool Array::isEmpty() {
    return length == 0;
}

void Array::swap(int i, int j) {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
}

int main() {
    Array arr(6);
    arr.add(-5);
    arr.add(5);
    arr.add(-15);
    arr.add(15);
    arr.add(69);
    arr.add(-69);
    arr.display();
    arr.MoveNegatives();
    cout << "After moving negatives to the left! " << endl;
    //char checkSorted = arr.isSorted() == 1 ? 'T' : 'F';

    arr.display();
    
    return 0;
}