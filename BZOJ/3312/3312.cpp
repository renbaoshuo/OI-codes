#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int k, n, w[20], s[N], f[1 << 17], ans;
bool flag;

inline int find(int x, int y) {
    int l = f[x],
        r = std::min(n, f[x] + w[y]);

    int res = l;
    while (l <= r) {
        int mid = l + r >> 1;

        if (s[mid] - s[f[x]] <= w[y]) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        s[i] = s[i - 1] + x;
    }

    for (int i = 0; i < 1 << k; i++) {
        for (int j = 0; j < k; j++) {
            if (!(i & (1 << j))) {
                f[i | (1 << j)] = std::max(f[i | (1 << j)], find(i, j));
            }
        }

        if (f[i] == n) {
            flag = true;

            int sum = 0;
            for (int j = 0; j < k; j++) {
                if (!(i & (1 << j))) sum += w[j];
            }

            ans = std::max(ans, sum);
        }
    }

    cout << (flag ? ans : -1) << endl;

    return 0;
}
