#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int n = 0, a = 0;
    while (cin >> c) {
        n++;
        if (c == 'a') {
            a++;
        }
    }
    cout << min(a * 2 - 1, n) << endl;
    return 0;
}
