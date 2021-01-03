#include <bits/stdc++.h>

using namespace std;

int n, x, y, val[33000], ans[16000];

struct node {
    int x, y;
} t[16000];

int lowbit(int x) {
    return x & (-x);
}

void add(int p, int v) {
    while (p <= 32001) {
        val[p] += v;
        p += lowbit(p);
    }
}

int sum(int p) {
    int ans = 0;
    while (p >= 1) {
        ans += val[p];
        p -= lowbit(p);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x++, y++;
        ans[sum(x)]++;
        add(x, 1);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}