#include <bits/stdc++.h>

using namespace std;

int n, a[100005], ans;

struct node {
    int val;
    node* next[2];

    ~node() {
        for (auto i : next) {
            delete i;
        }
    }
};

void insert(node* root, int x, int b) {
    if (!x) {
        root->val++;
        return;
    }
    if (root->next[(x >> b) & 1] == nullptr) root->next[(x >> b) & 1] = new node();
    insert(root->next[(x >> b) & 1], x - (((x >> b) & 1) << b), b - 1);
}

int search(node* root, int x) {
    int res = 0;
    node* p = root;
    for (int i = 30; i >= 0; i--) {
        if (p == nullptr) break;
        if (p->next[!((x >> i) & 1)] != nullptr) {
            res += 1 << i;
            p = p->next[!((x >> i) & 1)];
        } else {
            p = p->next[(x >> i) & 1];
        }
    }
    return res;
}

int main() {
    node* root = new node();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(root, a[i], 30);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, search(root, a[i]));
    }
    cout << ans << endl;
    delete root;
    return 0;
}
