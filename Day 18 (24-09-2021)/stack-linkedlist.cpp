#include <iostream>

using namespace std;

struct Node {
    int data; 
    Node *next;
};

class LinkedList {
    Node *head = NULL;
    public:
        // We can eliminate the keyword 'stuct' in C++ while declaring a structure.
        Node *getHead() {
            return head;
        }

        // Displaying all the elements of the linked list iteratively
        void display1() {
            Node *h = head;
            while(h) {
                cout << h->data << endl;
                h = h->next;
            }
        }

        void insertAtFirst(int x) {
            Node *n = new Node;
            n->data = x;
            n->next = head;
            head = n;
        }

        int deleteFirst() {
            if (head) {
                Node *p = head;
                int x = p->data;
                head = head->next;
                delete p;
                return x;
            }

            return INT32_MIN;
        }

};

class Stack{
    LinkedList *S;
    public:
        Stack() {
            S = new LinkedList;
        }

        ~Stack() {
            delete S;
        }

        void Push(int x) {
            S->insertAtFirst(x);
        }

        int Pop() {
            return S->deleteFirst();
        }

        void Display() {
            S->display1();
        }
};

int main() {
    Stack st;

    st.Push(99);
    st.Push(45);
    st.Push(87);
    st.Push(23);

    st.Display();

    cout << endl << st.Pop() << endl;
    cout << st.Pop() << endl;
    cout << st.Pop() << endl;
    cout << st.Pop() << endl;
    cout << st.Pop() << endl;
    return 0;
}