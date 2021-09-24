#include <iostream>

using namespace std;

class Stack {
    int size, top;
    int *S;

    bool isFull();
    bool isEmpty();
    public:
        Stack(int size) {
            top = -1; // Initially top should point at -1
            this->size = size;
            S = new int[size];
        }

        void Push(int x) {
            if (!isFull()) {
                top++;
                S[top] = x;
            } else {
                cout << "Stack is full!" << endl;
            }
        }

        int Pop() {
            if (!isEmpty()) {
                int x = S[top];
                top--;
                return x;
            } else {
                return INT32_MIN;
            }
        }

        int Peek(int index = 0) { // Default index is set 0 if somebody wants to know the last element pushed to the stack
            if (!isEmpty()) {
                if (index < size && index >= 0) {
                    return S[top - index]; // ALHUMDULILLAH
                } else {
                    return INT32_MIN;
                }
            } else {
                return INT32_MIN;
            }
        }
        void Display() {
            for (int i = top; i >= 0; i--)
                cout << S[i] << endl;
        }
};

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return size == (top + 1);
}

int main() {
    Stack s(4);

    s.Push(5);
    s.Push(4);
    s.Push(3);
    s.Push(2);

    cout << "Displaying Stack " << endl;
    s.Display();
    // cout << "Before popping " << endl;
    // s.Display();

    // int pop1 = s.Pop();
    // int pop2 = s.Pop();
    // int pop3 = s.Pop();
    // int pop4 = s.Pop();

    // cout << "After popping" << endl;
    // s.Display();

    // cout << "Pop1 --> " << pop1 << endl;
    // cout << "Pop2 --> " << pop2 << endl;
    // cout << "Pop3 --> " << pop3 << endl;
    // cout << "Pop4 --> " << pop4 << endl;

    cout << endl << "Peeking Zone " << endl;

    cout << "Peek(0) --> " << s.Peek(0) << endl;
    cout << "Peek(-1) --> " << s.Peek(-1) << endl;
    cout << "Peek(1) --> " << s.Peek(1) << endl;
    cout << "Peek(2) --> " << s.Peek(2) << endl;
    cout << "Peek(3) --> " << s.Peek(3) << endl;
    cout << "Peek(6) --> " << s.Peek(6) << endl;
    return 0;
}