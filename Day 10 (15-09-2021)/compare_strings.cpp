#include <iostream>

using namespace std;

bool compareStr(char *str1, char *str2) {
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i]!=str2[i]) {
            return false;
        }
    }

    return true;
}
int main() {
    
    return 0;
}