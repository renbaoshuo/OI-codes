#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<char> ans;
    int a = -1;
    char c = 'a';
    cin >> s;
    map<char, int> m, m1;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
        if (!m1.count(s[i])) m1[s[i]] = i;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (m[i] == 1) {
            ans.push_back(i);
        }
    }
    if (ans.empty()) {
        cout << "no" << endl;
    } else {
        for (char i : ans) {
            if (a == -1 || m1[i] < a) {
                a = m1[i];
                c = i;
            }
        }
        cout << c << endl;
    }
    return 0;
}
