#include <iostream>

using namespace std;

int length(char *string) {
    int l = 0;
    for (int i = 0; string[i] != '\0'; i++) {l++;}
    return l;
}

int main() {
    char name[20];

    cout << "Enter your name: " << endl;
    cin.getline(name, 1000);

    int nameLength = length(name);

    cout << "Your name is " << name << endl
    << "And, it consist of " << nameLength << " characters." << endl;
    
    return 0;
}