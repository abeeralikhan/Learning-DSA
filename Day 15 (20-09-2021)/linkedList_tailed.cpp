#include <iostream>

using namespace std;

struct Node {
    int data; 
    Node *next;
};

class LinkedList{
    public:
        Node *head = NULL, *tail = NULL;
        // We can eliminate the keyword 'stuct' in C++ while declaring a structure.

        void Add(int x) {
            Node *n = new Node;
            n->data = x;
            n->next = NULL;

            if (!head) {
                head = n;
                tail = head;

            } else {
                tail->next = n;
                tail = n;                          
            }
        }

        // Displaying all the elements of the linked list iteratively
        void display1() {
            Node *h = head;
            while(h) {
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

                while(h) {
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

                while(h) {
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
            while(h) {
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
                    if (!(h->next)) tail = h; // If we searched for the last node, and it's moving to the first. We need to update the tail.
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
                while(h->next) {
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
            Add(x);
        }

        void insert_sorted(int x) {
            if ((head->data > x) || !head) {
                insertAtFirst(x);

            } else {
                Node *h = head->next;
                int position = 2; 
                bool isInserted = false;

                while(h) {
                    if (h->data > x) {
                        insert(x, position-1); // Position-1 because we have to insert it before a node
                        isInserted = true;
                        break;
                    }
                    h = h->next;
                    position++;
                }

                if (!isInserted) {
                    insertAtLast(x);
                }
            }
        }

        void deleteFirst() {
            if (head) {
                Node *p = head;
                head = head->next;
                delete p;
            } else {
                cout << "Deletion Failed! There is no element in this linked list." << endl;
            }
        }

        void deleteLast() {
            if (head && tail) {
                if (head==tail) { // If head and tail are same, that means there's only one element in the list.
                    deleteFirst();
                } else {
                    Node *h = head;

                    while (h->next->next) {
                        h = h->next;
                    }
                    
                    delete h->next;
                    h->next = NULL;
                    tail = h;
                }

            } else {
                cout << "Deletion Failed! There is no element in this linked list." << endl;
            }
        }

        void deleteNode(int position) {
            if (head) {
                if (position==1) {
                    deleteFirst();
                } else {
                    Node *h = head;
                    int current_pos = 1;
                    for (int i = 1; i < position-1; i++) {
                        h = h->next;
                        current_pos++;
                    }

                    if (h->next == tail) {
                        // Code section copied from deleteLast function
                        delete h->next;
                        h->next = NULL;
                        tail = h;

                    } else {
                        Node *to_be_delete = h->next;
                        Node *its_next = to_be_delete->next;
                        
                        to_be_delete->next = NULL;
                        delete to_be_delete;

                        h->next = its_next;
                    }
                    
                }
            } else {
                cout << "Deletion Failed! There is no element in this linked list." << endl;
            }
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

    ll.Add(2);
    ll.Add(4);
    ll.Add(6);
    ll.Add(8);
    ll.Add(10);
    ll.insert_sorted(11);
    ll.insert_sorted(1);
    ll.insert_sorted(3);
    ll.insert_sorted(9);
    ll.insert_sorted(7);
    ll.insert_sorted(5);
    ll.display2();

    ll.deleteNode(5);
    ll.deleteNode(6);
    ll.deleteNode(9);
    ll.Add(55);
    ll.insertAtLast(99);
    
    cout << "After deletion" << endl;
    ll.display2();

    return 0;
}