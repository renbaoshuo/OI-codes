#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i % 2 && n % 2 && i < n - 4 || i % 2 && !(n % 2) && i != n - 1) {
            cout << '-';
        }
        if (i == n - 4 && n % 2) {
            cout << '-' << s[n - 3] << s[n - 2] << s[n - 1];
            break;
        }
    }
    return 0;
}
