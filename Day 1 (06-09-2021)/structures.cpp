#include <iostream>

using namespace std;

struct Card {
    int face_value;
    int shape;
    int color;
};

int main() {
    // Declaring a structure
    struct Card fiveOfDiamonds;

    // Declaring and Initializing a structure
    struct Card oneOfClubs = {1, 3, 4};
    cout << oneOfClubs.color << endl;
    cout << oneOfClubs.shape << endl;
    cout << oneOfClubs.face_value << endl;

    // Declaring an array of structures
    // Note: We can eliminate the keyword "struct" in c++
    Card deck[52];

    // Declaring and Initializing and array of structures
    Card premiumDeck[52] = {{1, 1, 1}, {1, 2, 3}, {3, 2, 1}}; // Initializing first three cards
    

    return 0;
}