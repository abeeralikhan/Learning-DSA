#include <iostream>

using namespace std;

bool validateString(char *);

int main() {
    char input[20]; 
    cout << "Enter a string: " << endl;
    cin.getline(input, 1000);

    if (validateString(input)) {
        cout << "You've entered a valid string!" << endl;
    } else {
        cout << "You've entered an invalid string!" << endl;
    }
    return 0;
}

bool validateString(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!(string[i]>=65 && string[i]<=90) && !(string[i]>=97 && string[i]<=122) &&
        !(string[i]>=48 && string[i]<=57)) {
            return false;
        }
    }
    return true;
}