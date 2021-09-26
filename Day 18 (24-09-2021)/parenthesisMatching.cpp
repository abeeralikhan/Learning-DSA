#include <iostream>

using namespace std;

struct Node {
    char data; 
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

        void insertAtFirst(char x) {
            Node *n = new Node;
            n->data = x;
            n->next = head;
            head = n;
        }

        int deleteFirst() {
            if (head) {
                Node *p = head;
                char x = p->data;
                head = head->next;
                delete p;
                return x;
            }

            return 'N';
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

char nextMatching (char parenthese) {

    switch (parenthese)
    {
    case '(':
        return ')';
        break;

    case '{':
        return '}';
        break;
    case '[':
        return ']';
        break;
    }

    return ' ';
}

bool verify_parenthesis(char *string) {
    Stack st;
    // char last = ' '; 
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
            st.Push(string[i]);
            count++;
        } else {
            char popped = st.Pop();
            count--;

            if (popped=='N') {
                return false;
            } 
        }
    }

    if (count != 0) {
        return false;
    }

    return true;
}

int main() {
    char data[20] = "{[()]}";
    
    cout << "Are parenthesis balanced? --> " << verify_parenthesis(data) << endl;

    return 0;
}