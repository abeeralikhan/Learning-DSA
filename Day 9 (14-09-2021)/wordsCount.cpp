#include <iostream>

using namespace std;

void wordCount(char *string) {
    int wcount = 1; 

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 32 && string[i-1] != 32) { // If previous character is space, don't count it.
            wcount++;
        }
    }

    cout << "There are " << wcount << " words in the string \"" << string << '\"' << endl;
}
int main() {
    char myString[] = "Hello, my name is abeer.       I am twentyone years     old.";

    wordCount(myString);

    return 0;
} 