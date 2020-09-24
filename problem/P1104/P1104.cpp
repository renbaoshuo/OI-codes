// R38823231

#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int    y, m, d, i;

    node() {
        name = "";
        y = m = d = i = 0;
    }
};

bool cmp(node a, node b) {
    if (a.y == b.y) {
        if (a.m == b.m) {
            if (a.d == b.d) {
                return a.i > b.i;
            }
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}

int main() {
    int  n;
    node a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].i = i;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].name << endl;
    }
    return 0;
}
