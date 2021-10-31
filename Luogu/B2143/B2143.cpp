#include <bits/stdc++.h>

using namespace std;

char itoc(int x) {
    char r;
    switch (x) {
        case 10: r = 'A'; break;
        case 11: r = 'B'; break;
        case 12: r = 'C'; break;
        case 13: r = 'D'; break;
        case 14: r = 'E'; break;
        case 15: r = 'F'; break;
        default: r = x + '0'; break;
    }
    return r;
}

int main() {
    string s, r;
    int x, m;
    cin >> x >> m;
    while (x) {
        r = itoc(x % m) + r;
        x /= m;
    }
    cout << r << endl;
    return 0;
}
