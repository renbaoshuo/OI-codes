#include <bits/stdc++.h>

using namespace std;

struct node {
    int i, t, k;
} p[500005];

bool cmp(node a, node b) {
    return a.t * a.k == b.t * b.k ? a.t == b.t ? a.i < b.i : a.t > b.t : a.t * a.k > b.t * b.k;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].t >> p[i].k;
        p[i].i = i;
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        cout << p[i].i << ' ';
    }
    cout << endl;
    return 0;
}
