#include <bits/stdc++.h>

using namespace std;

int main() {
    int us = 1, zs = 1;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < 7; i++) {
        if (a[i] <= 0) break;
        else us *= a[i] - 64;
    }
    for (int i = 0; i < 7; i++) {
        if (b[i] <= 0) break;
        else zs *= b[i] - '@';
    }
    us %= 47;
    zs %= 47;
    if (us == zs) cout << "GO" << endl;
    else cout << "STAY" << endl;
    return 0;
}