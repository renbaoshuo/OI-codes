#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s1, s2, g;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        g.push_back(min(s1[i], s2[i]));
        if (s1[i] < s2[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << g << endl;
    return 0;
}
