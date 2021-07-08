#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
map<string, int> m;
string s1, s2;

void dfs(int l, int k) {
    if (k > l) {
        m[s1] = ++cnt;
        return;
    }
    for (char c = (k == 1 ? 'a' : s1[k - 2] + 1); c <= 'z'; c++) {
        s1[k - 1] = c;
        dfs(l, k + 1);
    }
}

int main() {
    for (int i = 1; i <= 6; i++) {
        s1.clear();
        s1.resize(i);
        dfs(i, 1);
    }
    cin >> s2;
    cout << m[s2] << endl;
    return 0;
}
