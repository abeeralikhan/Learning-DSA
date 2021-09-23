#include <iostream>

using namespace std;

struct Node {
    int data; 
    Node *next;
};

class LinkedList{
    public:
        Node *head = NULL;
        // We can eliminate the keyword 'stuct' in C++ while declaring a structure.

        void Add(int x) {
            if (head==NULL) {
                head = new Node;
                head->next = NULL;
                head->data = x;

            } else {
                Node *h = head;
                while(h->next != NULL) {
                    h = h->next;
                }
                Node *n = new Node;
                n->data = x;
                n->next = NULL;
                h->next = n;               
            }
        }

        // Displaying all the elements of the linked list iteratively
        void display1() {
            Node *h = head;
            while(h != NULL) {
                cout << h->data << endl;
                h = h->next;
            }
        }

        // Displaying all the elements of linked list recursively
        void display2() {
            display2_recur(head);
        }

        int count_iterative() {
            if (head) {
                int count = 0;
                Node *h = head;

                while(h != NULL) {
                    count++;
                    h = h->next;
                }
 
                return count;
            } else {

                return -1; // -1 count means linked list doesn't have any element in it
            }
        }

        int count_recursive() {
            int c = 0;
            return count_recur(head, c);
        }

        int sum_iterative() {
            if (head) {
                Node *h = head;
                int sum = 0;

                while(h != NULL) {
                    sum+=h->data;
                    h = h->next;
                }

                return sum;
            }

            return 0;
        }

        int sum_recursive() {
            return sum_recur(head);
        }

        int maximum() {
            if (head) {
                Node *h = head;
                int max = INT32_MIN;
                // int max = head->data;

                while(h != NULL) {
                    if (h->data > max) {
                        max = h->data;
                    }
                    h = h->next;
                }

                return max;
            }

            return -9999; 
        }

        int max_recur() {
            return max_recur_(head);
        }

        Node *search(int key) { // Returning targetted node
            Node *h = head;
            while(h != NULL) {
                if (key == h->data)
                    return h;

                h = h->next;
            }
            return NULL;
        }

        Node *search_improved(int key) {
            // Searched node will be moved to the head. 
            // Therefore, next time when'll search for it. We won't be needing to traverse the entire list.
            Node *h = head;

            if (head->data == key) return head;

            while(h->next != NULL) {
                if (h->next->data == key) {
                    Node *key_node;

                    key_node = h->next;
                    h->next = key_node->next;
                    key_node->next = head;
                    head = key_node;

                    return key_node;
                }

                h = h->next;
            }

            return NULL;
        }

        void insert(int x, int index) {
            bool isInserted = false;

            if (index == 0) { // Node to be inserted before head
                insertAtFirst(x);
                isInserted = true;

            } else {
                int i = 1;
                Node *h = head;
                while(h->next != NULL) {
                    /* We won't be reaching to the last node, hence flag is using to making assured
                    whether node has been inserted in the list or not. Otherwise, we'll insert it at
                    the end of the list */
                    if (i==index) {
                        Node *n = new Node, *h_next = h->next;
                        n->data = x;
                        h->next = n;
                        n->next = h_next;
                        isInserted = true;
                        break;
                    }
                    i++;
                    h = h->next;
                }
            }
            // If node is not inserted at this point. We have to insert in at the end of the list.
            if (!isInserted) {
                // THIS PART CAN IMPOROVED BY USING h POINTER. WE CAN h->next = n;
                // WE WON'T BE NEEDING TO ITERATE THROUGH THE ENTIRE LIST AGAIN IN INSERTATEND
                insertAtLast(x);
            }
        }

        void insertAtFirst(int x) {
            Node *n = new Node;
            n->data = x;
            n->next = head;
            head = n;
        }

        void insertAtLast(int x) {
            // We're not using tail pointer at the point therefore we need to iterate throught the entire
            // list to reach to the last node. 
            Node *n = new Node, *h = head;
            n->data = x;
            n->next = NULL;

            while(h->next != NULL) {
                h = h->next;
            }
        
            h->next = n;
            n->next = NULL;

        }

    private:
        void display2_recur(Node *n) {
            if (n) {
                cout << n->data << endl;
                display2_recur(n->next);
            }
        }

        int count_recur(Node *n, int c) {
            if (n) {
                c+=1;
                return count_recur(n->next, c);
            }

            return c;

            // Another approach without the count parameter
            // if (p == 0) return 0;
            // else return 1 + count_recur(n->next)
        }

        int sum_recur(Node *n) {
            if (n) {
                return n->data + sum_recur(n->next);
            }

            return 0;
        }

        int max_recur_(Node *n) {
            int x = 0;
            if (n) {
                x = max_recur_(n->next);

                return x > n->data ? x : n->data;
            }

            return INT32_MIN;

        }
};

int main() {
    LinkedList ll; 

    ll.Add(3);
    ll.Add(4);
    ll.Add(55);
    ll.Add(6);
    ll.Add(10);
    ll.display2();

    cout << "Count: " << ll.count_iterative() << endl;
    cout << "Sum: " << ll.sum_recursive() << endl;
    cout << "Maximum Element: " << ll.max_recur() << endl;

    ll.insert(101, 5);
    ll.insert(102, 0);
    ll.insert(103, 3);
    ll.display2();

    return 0;
}