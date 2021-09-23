#include <iostream>

using namespace std;

class UpperTriangular {
    int non_zero, n, *A;

    public: 
        UpperTriangular(int n) {
            this->n = n;
            non_zero = (n*(n+1))/2;
            A = new int[non_zero];
        }
        void set(int i, int j, int x) {
            if (j>=i) {
                A[getPosition(i, j)] = x;
            } else {
                cout << "Invalid Index!" << endl;
            }
        }

        void display() {
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < n + 1; j++) {
                    if (j>=i) {
                        cout << A[getPosition(i, j)] << ' '; 
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }

        int get(int i, int j) {
            if (j>=i) {
                return A[getPosition(i, j)];
            } else {
                return -9999;
            }
        }

        private:
        int getPosition(int i, int j) {
            // i --> row 
            return (((i-1)*n)-(((i-2)*(i-1))/2)+(j-1));
        }
};
int main() {
    UpperTriangular LT(3);
    LT.set(1, 1, 1);
    LT.set(1, 2, 2);
    LT.set(1, 3, 3);
    LT.set(2, 2, 4);
    LT.set(2, 3, 5);
    LT.set(3, 3, 6);

    LT.display();

    return 0;
}