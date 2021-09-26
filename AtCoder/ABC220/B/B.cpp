#include <bits/stdc++.h>

using namespace std;

int k;
long long aa, bb, x;
string a, b;

int ctoi(char c) {
    int r;
    switch (c) {
        case 'A':
            r = 10;
            break;
        case 'B':
            r = 11;
            break;
        case 'C':
            r = 12;
            break;
        case 'D':
            r = 13;
            break;
        case 'E':
            r = 14;
            break;
        case 'F':
            r = 15;
            break;
        default:
            r = c - '0';
            break;
    }
    return r;
}

int main() {
    cin >> k >> a >> b;
    x = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        aa += ctoi(a[i]) * x;
        x *= k;
    }
    x = 1;
    for (int i = b.size() - 1; i >= 0; i--) {
        bb += ctoi(b[i]) * x;
        x *= k;
    }
    cout << aa * bb << endl;
    return 0;
}
