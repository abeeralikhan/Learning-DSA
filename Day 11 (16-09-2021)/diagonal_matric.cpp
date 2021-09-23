#include <iostream>

using namespace std;

class Diagonal {
    int n, *A;

    public:
        Diagonal(int n) {
            this->n = n;
            A = new int[n];
        }

        void set(int i, int j, int x) {
            if (i==j) {
                A[i-1] = x;
            } else {
                cout << "Invalid values!" << endl;
            }
        }

        int get(int i, int j) {
            if (i==j) {
                return A[i-1];
            } else {
                return -999999;
            }
        }

        void display() {
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < n + 1; j++) {
                    if (i==j) {
                        cout << A[i-1] << ' '; 
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }

        ~Diagonal() {
            delete[] A;
        }
};
int main() {
    Diagonal d_mat(4);

    d_mat.set(1, 1, 5);
    d_mat.set(2, 2, 9);
    d_mat.set(3, 3, 11);
    d_mat.set(4, 4, -3);

    d_mat.display();
    return 0;
}