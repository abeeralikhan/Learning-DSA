#include <iostream>

using namespace std;

int findLength(char *string) {
    int l = 0;
    for (int i = 0; string[i] != '\0'; i++) {l++;}
    return l;
}

void lowerCase(char *string) {
    int length = findLength(string);

    for (int i = 0; i < length; i++) {
        string[i]+=32;
    }
}

void upperCase(char *string) {
    int length = findLength(string);

    for (int i = 0; i < length; i++) {
        string[i]-=32;
    }
}

int main() {
    char lowered_name[20] = "abeer";
    char uppered_name[20] = "ZUBAIR";

    lowerCase(uppered_name);
    upperCase(lowered_name);

    cout << lowered_name << endl;
    cout << uppered_name << endl;
    return 0;
}