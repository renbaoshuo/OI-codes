#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << ((s[s.size() - 1] - '0') % 2 ? "odd" : "even") << endl;
    }
    return 0;
}
