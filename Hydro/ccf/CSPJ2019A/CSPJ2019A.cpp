#include <bits/stdc++.h>

using namespace std;

int ans;
string s;

int main() {
    cin >> s;
    for (auto c : s) {
        ans += c == '1';
    }
    cout << ans << endl;
    return 0;
}
