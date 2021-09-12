#include <bits/stdc++.h>

using namespace std;

int n;
char op;
string s;

struct node {
    int val;
    node* next[30];

    ~node() {
        for (auto i : next) {
            delete i;
        }
    }
};

void insert(node* root, string s) {
    if (s.empty()) {
        root->val++;
        return;
    }
    if (root->next[s[0] - 'a'] == nullptr) root->next[s[0] - 'a'] = new node();
    insert(root->next[s[0] - 'a'], s.substr(1));
}

int query(node* root, string s) {
    return s.empty() ? root->val : (root->next[s[0] - 'a'] == nullptr ? 0 : query(root->next[s[0] - 'a'], s.substr(1)));
}

int main() {
    node* root = new node();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op >> s;
        if (op == 'I') {
            insert(root, s);
        } else {
            cout << query(root, s) << endl;
        }
    }
    delete root;
    return 0;
}
