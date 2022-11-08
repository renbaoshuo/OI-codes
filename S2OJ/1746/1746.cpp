#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 300005;

int q, st[N << 1][20];
std::string s;

std::vector<int> manacher(const std::string &_s) {
    int n = _s.size();
    std::string s(n * 2 + 3, '#');

    for (int i = 0; i < n; i++) {
        s[i * 2 + 2] = _s[i];
    }

    s[0] = '^';
    s[n * 2 + 2] = '$';

    std::vector<int> p(s.size(), 1);

    for (int i = 1, mid = 0, r = 0; i <= n * 2 + 1; i++) {
        p[i] = i < r ? std::min(p[mid * 2 - i], r - i) : 1;

        while (s[i - p[i]] == s[i + p[i]]) p[i]++;

        if (i + p[i] - 1 > r) {
            r = i + p[i] - 1;
            mid = i;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     p[i] = p[i * 2 + 2] / 2;
    // }

    // p.resize(n);

    return p;
}

int query(int l, int r) {
    if (l > r) return 1;
    int k = std::__lg(r - l + 1);
    return std::max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> q;

    auto p = manacher(s);
    int n = s.size();
    int t = std::__lg(p.size());

    for (int i = 1; i <= p.size(); i++) {
        st[i][0] = p[i - 1];
    }

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= p.size() - (1 << i) + 1; j++) {
            st[j][i] = std::max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }

    while (q--) {
        int ql, qr;

        cin >> ql >> qr;

        ql = (ql + 1) * 2 + 1;
        qr = (qr + 1) * 2 + 1;

        int l = 1,
            r = qr - ql + 1,
            res = 1;

        while (l <= r) {
            int mid = l + r >> 1;

            if (query(ql + mid - 1, qr - mid + 1) - 1 >= mid) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << res << endl;
    }

    return 0;
}
