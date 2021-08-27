#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

struct node {
    int t;
    long long p;

    node() {}
    node(int _t, long long _p)
        : t(_t), p(_p) {}
};

int n, t;
long long d, p, ans, bat, res[500005], tmp;
set<pair<long long, int>> s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        bat -= d;
        while (d > 0) {
            while (!s.empty() && !res[s.begin()->second]) {
                s.erase(s.begin());
            }
            tmp = min(d, res[s.begin()->second]);
            d -= tmp;
            res[s.begin()->second] -= tmp;
            while (!s.empty() && res[s.begin()->second] == 0) {
                s.erase(s.begin());
            }
        }
        cin >> d >> p;
        if (d > t) {
            cout << -1 << endl;
            exit(0);
        }
        while (!s.empty() && p < s.rbegin()->first) {
            ans -= res[s.rbegin()->second] * s.rbegin()->first;
            ans += p * res[s.rbegin()->second];
            res[i] += res[s.rbegin()->second];
            res[s.rbegin()->second] = 0;
            s.erase(--s.end());
            s.insert(make_pair(p, i));
        }
        if (bat < t) {
            tmp = t - bat;
            ans += tmp * p;
            res[i] += tmp;
            s.insert(make_pair(p, i));
            bat = t;
        }
    }
    bat -= d;
    while (d > 0) {
        while (!s.empty() && (res[s.begin()->second] == 0)) {
            s.erase(s.begin());
        }
        tmp = min(d, res[s.begin()->second]);
        d -= tmp;
        res[s.begin()->second] -= tmp;
        while (!s.empty() && res[s.begin()->second] == 0) {
            s.erase(s.begin());
        }
    }
    while (!s.empty()) {
        ans -= res[s.begin()->second] * s.begin()->first;
        res[s.begin()->second] = 0;
        s.erase(s.begin());
    }
    cout << ans << endl;
    return 0;
}
