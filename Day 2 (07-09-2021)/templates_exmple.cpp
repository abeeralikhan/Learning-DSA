#include <iostream>

using namespace std;

template <class T> // Making a template for class Stack so we can use it with multiple datatypes
class Stack
{
    T *arr; // Replace datatype with 'T' where we want it to be dynamic
    int i, count, size;

    public:     
        Stack(int size) {
            this->size = size;
            arr = new T[size];
            cout << "Memory has been allocated for an array of size " << size << endl;
            // Initializing the stack with all elements to be 0; 
            for(int j = 0; j < size; j++)
            arr[j] = j+1;
        }

        ~Stack() {
            delete[] arr;
            cout << "Memory has been deallocated" << endl;
        }

        void printStack() {
            for(int x = 0; x < size; x++)
            cout << arr[x] << " size --> "<< sizeof(arr[x]) << endl;
        }

        T sumElements() {
            T sum = 0;
            for(int x = 0; x < size; x++)
            sum+=arr[x];
            return sum;
        }
};
int main() {
    Stack<int> stack_int(5);
    Stack<double> stack_double(3);
    //Stack<char> stack_char(5);

    stack_int.printStack();
    stack_double.printStack();

    cout << "Sum elements :  " << stack_int.sumElements() << endl;
    cout << "Sum elements :  " << stack_double.sumElements() << endl;
    //stack_char.printStack();
    return 0;
}