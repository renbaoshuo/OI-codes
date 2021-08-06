#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    char op;
    cin >> op;

    for (char c : s) {
        if (c != op) {
            cout << c;
        } else {
            cout << '#';
        }
    }

    return 0;
}
