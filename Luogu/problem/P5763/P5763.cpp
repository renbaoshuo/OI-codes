#include <bits/stdc++.h>

using namespace std;

struct node {
    int t, m, p, s;

    bool operator<(const node& x) const {
        return s < x.s;
    }
};

int n, t, m, p, w = 0x3f3f3f3f, ans, cnt;
queue<node> wait;
vector<node> mem;
node x;

bool assign(int t) {
    if (mem.empty() || mem[0].s >= x.m) {
        x.s = 0;
        x.t = t;
        mem.push_back(x);
        sort(mem.begin(), mem.end());
        return true;
    }
    for (int i = 1; i < mem.size(); i++) {
        if (mem[i].s - (mem[i - 1].s + mem[i - 1].m) >= x.m) {
            x.s = mem[i - 1].s + mem[i - 1].m;
            x.t = t;
            mem.push_back(x);
            sort(mem.begin(), mem.end());
            return true;
        }
    }
    if (n - ((--mem.end())->s + (--mem.end())->m) >= x.m) {
        x.s = (--mem.end())->s + (--mem.end())->m;
        x.t = t;
        mem.push_back(x);
        sort(mem.begin(), mem.end());
        return true;
    }
    return false;
}

void release() {
    int nw = 0x3f3f3f3f;
    for (int i = 0; i < mem.size(); i++) {
        if (mem[i].t + mem[i].p == w) {
            mem.erase(mem.begin() + i--);
        } else {
            nw = min(nw, mem[i].t + mem[i].p);
        }
    }
    while (!wait.empty()) {
        x = wait.front();
        if (assign(w)) {
            nw = min(nw, wait.front().t + wait.front().p);
            wait.pop();
            cnt++;
        } else {
            break;
        }
    }
    w = nw;
}

int main() {
    cin >> n;
    while (cin >> t >> m >> p, t || m || p) {
        while (t >= w) release();
        x.t = t;
        x.m = m;
        x.p = p;
        if (assign(t)) {
            w = min(w, t + p);
        } else {
            wait.push(x);
        }
    }
    while (!wait.empty()) release();
    ans = w;
    for (int i = 0; i < mem.size(); i++) {
        ans = max(ans, mem[i].t + mem[i].p);
    }
    cout << ans << endl
         << cnt << endl;
    return 0;
}
