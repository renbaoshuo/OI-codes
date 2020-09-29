#include <bits/stdc++.h>

using namespace std;

int main() {
    int    x = 0, y = 0, t = 0, i = 0;
    string s;
    cin >> s >> t;
    while (t--) {
        if (i >= s.size()) {
            i = 0;
        }
        switch (s[i]) {
            case 'E': x++; break;
            case 'S': y--; break;
            case 'W': x--; break;
            case 'N': y++; break;
        }
        i++;
    }
    cout << x << ' ' << y << endl;
    return 0;
}
