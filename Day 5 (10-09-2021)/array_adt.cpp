#include <iostream>

using namespace std;

class Array {
    int *A, size, length = 0;

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

        int getSize() {
            return length;
        }
        

    private:
        bool isFull() {
            return size==length;
        }
};
int main() {
    Array arr(6);
    arr.add(5);
    arr.add(10);
    arr.add(1);
    arr.add(15);
    arr.insert(11, 2);
    arr.add(69);
    arr.display();
    cout << "Size: " << arr.getSize() << endl;
    cout << "Linear Search --> Input: 1 Ouput: " << arr.linearSearch(1) << endl; 
    return 0;
}