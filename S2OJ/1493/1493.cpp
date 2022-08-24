#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25;

int r, p, s, f[1 << N];
std::string sr[N], sp[N], ss[N];

int highbit(int x) {
    return 32 - __builtin_clz(x) - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> p >> s;

    sr[0] = "R", sp[0] = "P", ss[0] = "S";

    for (int i = 1; i <= 20; i++) {
        f[1 << i] = i;
    }

    for (int i = 1; i <= 20; ++i) {
        sp[i] = std::min(sr[i - 1] + ss[i - 1], ss[i - 1] + sr[i - 1]);
        sr[i] = std::min(ss[i - 1] + sp[i - 1], sp[i - 1] + ss[i - 1]);
        ss[i] = std::min(sp[i - 1] + sr[i - 1], sr[i - 1] + sp[i - 1]);
    }

    if (f[r + p + s] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else if (r != p && r != s && p == s && std::abs(r - s) == 1) {
        cout << sr[f[r + p + s]] << endl;
    } else if (p != r && p != s && r == s && std::abs(p - r) == 1) {
        cout << sp[f[r + p + s]] << endl;
    } else if (s != p && s != r && p == r && std::abs(s - p) == 1) {
        cout << ss[f[r + p + s]] << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
