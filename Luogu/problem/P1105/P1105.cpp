#include <bits/stdc++.h>

using namespace std;

int n, ans[20005];

struct node {
    int id, h, l, r;
    struct {
        int l, r;
    } ans;
} a[1005];

bool cmp1(node a, node b) {
    return a.h == b.h ? a.id > b.id : a.h < b.h;
}

bool cmp2(node a, node b) {
    return a.id < b.id;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].h >> a[i].l >> a[i].r;
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < n; i++) {
        a[i].ans.l = ans[a[i].l];
        a[i].ans.r = ans[a[i].r];
        for (int j = a[i].l + 1; j <= a[i].r - 1; j++) {
            ans[j] = a[i].id;
        }
    }
    sort(a, a + n, cmp2);
    for (int i = 0; i < n; i++) {
        cout << a[i].ans.l << ' ' << a[i].ans.r << endl;
    }
    return 0;
}
