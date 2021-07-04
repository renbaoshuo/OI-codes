#include <bits/stdc++.h>

using namespace std;

int main() {
    string k, c;
    int    t = 0;
    cin >> k >> c;
    for (int i = 0; i < c.size(); i++) {
        t = (k[i % k.size()] & 31) - 1;
        if((c[i] & 31) - t > 0) {
            c[i] = c[i] - t;
        }
        else {
            c[i] = c[i] - t + 26;
        }
    }
    cout << c << endl;
    return 0;
}
