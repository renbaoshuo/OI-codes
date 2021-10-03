#include <bits/stdc++.h>

using namespace std;

int n, u, v, w, a[100005], ans;
vector<pair<int, int>> g[100005];

struct node {
    int size;
    node* next[2];

    ~node() {
        for (auto& i : next) {
            delete i;
        }
    }
};

void dfs(int u, int fa, int sum) {
    a[u] = sum;
    for (auto i : g[u]) {
        if (i.first != fa) {
            dfs(i.first, u, sum ^ i.second);
        }
    }
}

void insert(node* root, int x, int b) {
    if (!x) {
        root->size++;
        return;
    }
    if (root->next[(x >> b) & 1] == nullptr) root->next[(x >> b) & 1] = new node();
    insert(root->next[(x >> b) & 1], x - (((x >> b) & 1) << b), b - 1);
}

int query(node* root, int x) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        if (root == nullptr) break;
        if (root->next[!((x >> i) & 1)] != nullptr) {
            res += 1 << i;
            root = root->next[!((x >> i) & 1)];
        } else {
            root = root->next[(x >> i) & 1];
        }
    }
    return res;
}

int main() {
    node* root = new node();
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        insert(root, a[i], 31);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, query(root, a[i]));
    }
    cout << ans << endl;
    return 0;
}
