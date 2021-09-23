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
    arr.add(1);
    arr.add(5);
    arr.add(10);
    arr.add(15);
    arr.add(69);
    arr.display();
    cout << "Size: " << arr.GetSize() << endl;
    cout << "Binary Search --> Input: 15 Ouput: " << arr.BinarySearch(70) << endl; 
    
    return 0;
}