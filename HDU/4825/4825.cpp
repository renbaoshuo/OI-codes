#include <bits/stdc++.h>

using namespace std;

int t, n, m, a;

struct node {
    int val;
    node* next[2];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void insert(node* root, int x) {
    for (int i = 30; i >= 0; i--) {
        if (root->next[(x >> i) & 1] == nullptr) root->next[(x >> i) & 1] = new node();
        root = root->next[(x >> i) & 1];
    }
    root->val = x;
}

int query(node* root, int x) {
    for (int i = 30; i >= 0; i--) {
        if (root == nullptr) break;
        if (root->next[!((x >> i) & 1)] != nullptr) {
            root = root->next[!((x >> i) & 1)];
        } else {
            root = root->next[(x >> i) & 1];
        }
    }
    return root->val;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":" << endl;
        node* root = new node();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a;
            insert(root, a);
        }
        for (int i = 0; i < m; i++) {
            cin >> a;
            cout << query(root, a) << endl;
        }
        delete root;
    }
    return 0;
}
