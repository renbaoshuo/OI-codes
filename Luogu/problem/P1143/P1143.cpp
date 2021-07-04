// R38915106

#include <bits/stdc++.h>

using namespace std;

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

char itoc(int x) {
    char r;
    switch (x) {
        case 10:
            r = 'A';
            break;
        case 11:
            r = 'B';
            break;
        case 12:
            r = 'C';
            break;
        case 13:
            r = 'D';
            break;
        case 14:
            r = 'E';
            break;
        case 15:
            r = 'F';
            break;
        default:
            r = x + '0';
            break;
    }
    return r;
}

int main() {
    long long i, n = 0, p1, p2, x = 1;
    string    s, res = "";
    cin >> p1 >> s >> p2;
    for (i = s.size() - 1; i >= 0; i--) {
        n += ctoi(s[i]) * x;
        x *= p1;
    }
    while (n != 0) {
        res = itoc(n % p2) + res;
        n /= p2;
    }
    cout << res << endl;
    return 0;
}
