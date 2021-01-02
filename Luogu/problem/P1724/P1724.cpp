// R39244100

#include <bits/stdc++.h>

using namespace std;

int    x = 0, y = 0, t = 0;
string s;

int main() {
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
            case 'E': x++; break;
            case 'S': y--; break;
            case 'W': x--; break;
            case 'N': y++; break;
        }
    }
    x *= (int)(t / s.size());
    y *= (int)(t / s.size());
    for (int i = 0; i < t % s.size(); i++) {
        switch (s[i]) {
            case 'E': x++; break;
            case 'S': y--; break;
            case 'W': x--; break;
            case 'N': y++; break;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
