#include <bits/stdc++.h>

using namespace std;

int n;
map<char, int> m;
string a, s[50005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        m[a[i]] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, [](string a, string b) {
        string aa, bb;
        for (char c : a) {
            aa.push_back(m[c] + 'a');
        }
        for (char c : b) {
            bb.push_back(m[c] + 'a');
        }
        return aa < bb;
    });
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
