#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (char c : s) {
        if ('A' <= c && c <= 'Z') {
            cout << char((c - 'A' + 1) % 26 + 'A');
        } else if ('a' <= c && c <= 'z') {
            cout << char((c - 'a' + 1) % 26 + 'a');
        } else {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
