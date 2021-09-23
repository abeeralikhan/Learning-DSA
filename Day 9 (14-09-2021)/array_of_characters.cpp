#include <iostream>

using namespace std;

int main() {
    char name[20] = {'A', 'B', 'E', 'E', 'R', '\0'};
    char name2[] = {'J', 'A', 'H', 'A', 'N', 'G', 'I', 'R', '\0'};

    char yolo[] = "Valeed";
    char hoho[10] = "Valeeda";
    char city[] = "Abdul Jabbar";

    // Below declaration will declare string inside the heap memory, whereas pointer will remain in the stack
    const char *in_heap = "Abeer";
    char bro[20]; 

    cout << "Enter your name: " << endl;
    //cin >> bro;
    cin.getline(bro, 100);
    cout << "Your name is " << bro << endl;
    return 0;
}