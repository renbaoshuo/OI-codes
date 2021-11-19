#include <bits/stdc++.h>

using namespace std;

string pre, in, post;

void dfs(string pre, string in) {
    if (pre.empty()) {
        return;
    }
    char root = pre[0];
    int k = in.find(root);
    pre.erase(pre.begin());
    string leftpre = pre.substr(0, k);
    string rightpre = pre.substr(k);
    string leftin = in.substr(0, k);
    string rightin = in.substr(k + 1);
    dfs(leftpre, leftin);
    dfs(rightpre, rightin);
    post.push_back(root);
}

int main() {
    cin >> in >> pre;
    dfs(pre, in);
    cout << post << endl;
    return 0;
}
