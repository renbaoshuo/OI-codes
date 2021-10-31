#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000005], ans;

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
    for (int i = 21; i >= 0; i--) {
        if (root->next[(x >> i) & 1] == nullptr) root->next[(x >> i) & 1] = new node();
        root = root->next[(x >> i) & 1];
        root->val++;
    }
}

int search(node* root, int x) {
    int res = 0;
    node* p = root;
    for (int i = 21; i >= 0; i--) {
        int c = (x >> i) & 1;
        int t = (k >> i) & 1;
        if (t && p->next[1 - (c ^ t)] != nullptr) {
            res += p->next[1 - (c ^ t)]->val;
        }
        if (p->next[c ^ t] == nullptr) break;
        p = p->next[c ^ t];
    }
    return res;
}

int main() {
    node* root = new node();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(root, a[i]);
    }
    for (int i = 0; i <= 2097151; i++) {
        ans = max(ans, search(root, i));
    }
    cout << ans << endl;
    delete root;
    return 0;
}
