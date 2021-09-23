#include <iostream>

using namespace std;

// 97 ---> 'a'
// 122 ---> 'z'

void toUpper(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i]>=97 && string[i]<=122) {
            string[i]+=-32;
        }
    }
}

int main() {
    char test1[20] = "abeer ali khan";
    char test2[20] = "Abeer Ali Khan";
    char test3[20] = "ABEER ALI KHAN";

    toUpper(test1);
    toUpper(test2);
    toUpper(test3);

    cout << "Input: \"abeer ali khan\" --> Output: " << test1 << endl;
    cout << "Input: \"Abeer Ali Khan\" --> Output: " << test2 << endl;
    cout << "Input: \"ABEER ALI KHAN\" --> Output: " << test3 << endl;
    return 0;
}