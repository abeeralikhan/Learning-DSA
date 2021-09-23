#include <iostream>

using namespace std;

void vowelsConsonants(char *string) {
    int vcount = 0, ccount = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' ||string[i] == 'i' ||string[i] == 'o' ||string[i] == 'u' ||
        string[i] == 'A' ||string[i] == 'E' ||string[i] == 'I' ||string[i] == 'O' ||string[i] == 'U') {
            vcount++;
        } else if ((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122)) {
            ccount++;
        }
    }

    cout << "Entered string \"" << string << "\" has " << endl <<
    vcount << " Vowel(s)" << endl <<
    ccount << " Consonant(s)" << endl; 
}

int main() {
    char myString[] = "Abeer Ali Khan";

    vowelsConsonants(myString);

    return 0;
}