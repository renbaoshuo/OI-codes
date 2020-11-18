#include <bits/stdc++.h>

using namespace std;

struct node {
    long long w, c;

    node() {
        w = 0;
        c = 0;
    }
    node(long long _w, long long _c) {
        w = _w;
        c = _c;
    }

    bool operator<(const node a) const {
        return c < a.c;
    }
};

int main() {
    long long op;
    node      ans;
    set<node> a;
    while (cin >> op, op != -1) {
        if (op == 1) {
            long long w, c;
            cin >> w >> c;
            a.insert(node(w, c));
        }
        else if (op == 2 && !a.empty()) {
            a.erase(--a.end());
        }
        else if (op == 3  && !a.empty()) {
            a.erase(a.begin());
        }
    }
    for (set<node>::iterator it = a.begin(); it != a.end(); it++) {
        ans.c += it->c;
        ans.w += it->w;
    }
    cout << ans.w << ' ' << ans.c << endl;
    return 0;
}
