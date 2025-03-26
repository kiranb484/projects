#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void tower(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disc 1 from " << A << " to " << C << endl;
        return;
    }
    tower(n - 1, A, C, B);
    cout << "Move disc " << n << " from " << A << " to " << C << endl;
    tower(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Input number of discs :";
    cin >> n;
    while (n < 1) {
        cout << "Invalid input";
        cin >> n;
    }
    tower(n, 'A', 'B', 'C');
    return 0;
}