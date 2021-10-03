#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
string s;

struct node {
    int size;
    node* next[26];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void insert(node* root, string s) {
    if (s.empty()) {
        root->size++;
        return;
    }
    if (root->next[s[0] - 'a'] == nullptr) root->next[s[0] - 'a'] = new node();
    insert(root->next[s[0] - 'a'], s.substr(1));
}

int query(node* root, string s) {
    if (s.empty()) return root->size;
    if (root->next[s[0] - 'a'] == nullptr) return 0;
    return query(root->next[s[0] - 'a'], s.substr(1));
}

int main() {
    node* root = new node();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert(root, s);
    }
    for (int i = 1; i <= m; i++) {
        ans = 0;
        cin >> s;
        for (int j = 1; j <= s.size(); j++) {
            ans += query(root, s.substr(0, j));
        }
        cout << ans << endl;
    }
    delete root;
    return 0;
}
