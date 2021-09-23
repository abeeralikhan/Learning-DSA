#include <iostream>

using namespace std;

// 65 ---> 'A'
// 90 ---> 'Z'

void toLower(char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i]>=65 && string[i]<=90) {
            string[i]+=32;
        }
    }
}

int main() {
    char test1[20] = "ABEER ALI KHAN";
    char test2[20] = "aBeEr AlI kHaN";
    char test3[20] = "abeer ali khan";

    toLower(test1);
    toLower(test2);
    toLower(test3);

    cout << "Input: \"ABEER ALI KHAN\" --> Output: " << test1 << endl;
    cout << "Input: \"aBeEr AlI kHaN\" --> Output: " << test2 << endl;
    cout << "Input: \"abeer ali khan\" --> Output: " << test3 << endl;
    return 0;
}