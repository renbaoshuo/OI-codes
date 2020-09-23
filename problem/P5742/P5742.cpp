// R38780150

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, s, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp >> x >> s;
        if (x + s > 140 && x * 0.7 + s * 0.3 >= 80) {
            cout << "Excellent" << endl;
        }
        else {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}
