#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int min, max;

    node() {
        l = r = 0;
        min = 0x3f3f3f3f;
        max = -0x3f3f3f3f;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        min = 0x3f3f3f3f;
        max = -0x3f3f3f3f;
    }
} tr[1000005 << 2];
int n, k, a[1000005];

void pushup(int u) {
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].max = tr[u].min = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

pair<int, int> query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return make_pair(tr[u].max, tr[u].min);
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pair<int, int> ans, tmp;
    ans.first = -0x3f3f3f3f;
    ans.second = 0x3f3f3f3f;
    if (l <= mid) {
        tmp = query(u << 1, l, r);
        ans.first = max(ans.first, tmp.first);
        ans.second = min(ans.second, tmp.second);
    }
    if (r > mid) {
        tmp = query(u << 1 | 1, l, r);
        ans.first = max(ans.first, tmp.first);
        ans.second = min(ans.second, tmp.second);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    vector<int> ans_min, ans_max;
    for (int i = 1; i + k - 1 <= n; i++) {
        pair<int, int> tmp = query(1, i, i + k - 1);
        ans_max.push_back(tmp.first);
        ans_min.push_back(tmp.second);
    }
    for (int i = 0; i < ans_min.size(); i++) {
        printf("%d ", ans_min[i]);
    }
    printf("\n");
    for (int i = 0; i < ans_max.size(); i++) {
        printf("%d ", ans_max[i]);
    }
    printf("\n");
    return 0;
}
