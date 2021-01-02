// R38856378

#include <bits/stdc++.h>

using namespace std;

string d(int x, int i, string s) {
    if (x == 0) {
        return "0";
    }
    do {
        if (x & 1) {
            s = (i == 1 ? "2" : "2(" + d(i, 0, "") + ")") + (s == "" ? "" : "+") + s;
        }
    } while (++i, x >>= 1);
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << d(n, 0, "") << endl;
    return 0;
}
