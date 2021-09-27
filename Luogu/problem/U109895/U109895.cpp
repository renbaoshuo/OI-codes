#include <bits/stdc++.h>

using namespace std;

int t, n, m;
long long a;

struct node {
    long long val;
    node* next[2];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void insert(node* root, long long x) {
    for (int i = 31; i >= 0; i--) {
        if (root->next[(x >> i) & 1] == nullptr) root->next[(x >> i) & 1] = new node();
        root = root->next[(x >> i) & 1];
    }
    root->val = x;
}

long long query(node* root, long long x) {
    for (int i = 31; i >= 0; i--) {
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
    node* root = new node();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        insert(root, a);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a);
        printf("%lld\n", query(root, a));
    }
    delete root;
    return 0;
}
