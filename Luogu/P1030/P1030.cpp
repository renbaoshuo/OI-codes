#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;

void dfs(string s1, string s2) {
    if (!s1.size()) return;
    char root = *--s2.end();
    int k = s1.find(root);
    s3.push_back(root);
    dfs(s1.substr(0, k), s2.substr(0, k));
    dfs(s1.substr(k + 1), s2.substr(k, s2.size() - k - 1));
    return;
}

int main() {
    cin >> s1 >> s2;
    dfs(s1, s2);
    cout << s3 << endl;
    return 0;
}
