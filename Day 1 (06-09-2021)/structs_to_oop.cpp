#include <iostream>

using namespace std;

class Rectangle
{
    int length;
    int breadth;

    public:
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }

        int area() {
            return length * breadth;
        }

        void changeLength(int newLength) {
            length = newLength;
        }

        void display() {
            cout << "Length: " << length << "; Breadth: " << breadth << endl;
        }
};

int main() {
    Rectangle rect(10, 5);
    rect.display();
    cout << "Area: " << rect.area() << endl;
    rect.changeLength(12);
    rect.display();
    cout << "Area: " << rect.area() << endl;
    return 0;
}