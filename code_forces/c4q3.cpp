#include <iostream>
#include <string>

using namespace std;

string canReachDestination(int n, const string& row1, const string& row2) {
    int currentRow = 0, currentCol = 0;

    while (currentRow < 2 || currentCol != n - 1) {
        if (currentRow == 0) {
            if (row1[currentCol] == '>') {
                currentCol++;
            } else {
                currentCol--;
            }
        } else {
            if (row2[currentCol] == '>') {
                currentCol++;
            } else {
                currentCol--;
            }
        }

        if (currentCol < 0 || currentCol >= n) {
            return "NO";
        }

        currentRow = 1 - currentRow;
    }

    return "YES";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;

        cout << canReachDestination(n, row1, row2) << endl;
    }

    return 0;
}
