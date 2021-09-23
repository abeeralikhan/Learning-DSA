#include <iostream>

using namespace std;

struct Rectangle
{
    int lenght;
    int breadth;
};

void initialize(Rectangle *r, int l, int b) {
    r->breadth = b;
    r->lenght = l;
}

int area(Rectangle r) {
    return r.lenght * r.breadth;
}

void changeBreadth(Rectangle *r, int newBreadth) {
    r->breadth = newBreadth;
}

int main() {
    struct Rectangle r;

    initialize(&r, 10, 5);
    cout << area(r) << endl;
    changeBreadth(&r, 6);
    cout << area(r) << endl;
    return 0;
}