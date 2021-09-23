#include <iostream>

using namespace std;

class LowerTriangular {
    int non_zero, n, *A;

    public: 
        LowerTriangular(int n) {
            this->n = n;
            non_zero = (n*(n+1))/2;
            A = new int[non_zero];
        }
        void set(int i, int j, int x) {
            if (i>=j) {
                A[getPosition(i, j)] = x;
            } else {
                cout << "Invalid Index!" << endl;
            }
        }

        void display() {
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < n + 1; j++) {
                    if (i>=j) {
                        cout << A[getPosition(i, j)] << ' '; 
                    } else {
                        cout << "0 ";
                    }
                }
                cout << endl;
            }
        }

        int get(int i, int j) {
            if (i>=j) {
                return A[getPosition(i, j)];
            } else {
                return -9999;
            }
        }

    private:
        int getPosition(int i, int j) {
            // i --> row 
            int row = 0;
            for (int sum = 1; sum < i; sum++)
                row+=sum;

            return row+j-1;
        }
};
int main() {
    LowerTriangular LT(3);
    LT.set(1, 1, 1);
    LT.set(2, 1, 2);
    LT.set(2, 2, 3);
    LT.set(3, 1, 4);
    LT.set(3, 2, 5);
    LT.set(3, 3, 6);

    LT.display();

    return 0;
}