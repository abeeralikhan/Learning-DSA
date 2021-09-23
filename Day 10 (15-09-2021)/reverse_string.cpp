#include <iostream>

using namespace std;

int length(char *string) {
    int l = 0;
    for (int i = 0; string[i] != '\0'; i++) {l++;}
    return l;
}

char* reverse(char *string) {
    int sLength = length(string);
    char *reversedStr = new char[sLength+1];

    for (int i = sLength-1, j = 0; i >= 0; i--, j++) {
        reversedStr[j] = string[i]; 
    }

    reversedStr[sLength] = '\0';

    return reversedStr;
}

int main() {
    char name[] = "Abeer Ali Khan";

    char *reversedString = reverse(name);

    cout << reversedString;
    return 0;
}