// R38818598

#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    bool towards;
};

int main() {
    // freopen("data/P1563_sample1.in", "r", stdin);
    int n, m, now = 0, x, y;
    node a[100005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].towards >> a[i].name;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (a[now].towards == 0) {
            if (x == 0) {
                now = (now + n - y) % n;
            } else if (x == 1) {
                now = (now + y) % n;
            }
        } else if (a[now].towards == 1) {
            if (x == 0) {
                now = (now + y) % n;
            } else if (x == 1) {
                now = (now + n - y) % n;
            }
        }
    }
    cout << a[now].name << endl;
    return 0;
}
