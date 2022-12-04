#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

class BIT {
  private:
    int data[N];

    static int lowbit(int x) {
        return x & -x;
    }

  public:
    void add(int x, int v) {
        for (; x < N; x += lowbit(x)) {
            data[x] += v;
        }
    }

    int query(int x) {
        int ans = 0;

        for (; x; x -= lowbit(x)) {
            ans += data[x];
        }

        return ans;
    }
};

int n, a[N], pre_sm[N], suf_sm[N];
long long ans;
BIT bit_pre, bit_suf;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        pre_sm[i] = bit_pre.query(a[i] - 1);
        bit_pre.add(a[i], 1);
    }

    for (int i = n; i; i--) {
        suf_sm[i] = bit_suf.query(a[i] - 1);
        bit_suf.add(a[i], 1);
    }

    for (int i = 1; i <= n; i++) {
        int pre_lg = i - pre_sm[i] - 1,
            suf_lg = n - i - suf_sm[i];

        ans += static_cast<long long>(pre_sm[i]) * suf_lg                                                            // 123
             + static_cast<long long>(pre_lg) * (pre_lg - 1) / 2 - static_cast<long long>(pre_lg) * suf_sm[i]        // 231 = **1 - 321
             + static_cast<long long>(suf_sm[i]) * (suf_sm[i] - 1) / 2 - static_cast<long long>(pre_lg) * suf_sm[i]  // 312 = 3** - 321
            ;
    }

    cout << ans << endl;

    return 0;
}
