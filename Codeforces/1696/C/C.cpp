#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int t, n, m, k, a[N], b[N];

void expand(int *arr, int n, int m, std::vector<std::pair<long long, long long>> &vec) {
    for (int i = 1; i <= n; i++) {
        long long x = arr[i],
                  cnt = 1;

        while (x % m == 0) {
            x /= m;
            cnt *= m;
        }

        if (!vec.empty() && vec.rbegin()->first == x) {
            vec.rbegin()->second += cnt;
        } else {
            vec.push_back(std::make_pair(x, cnt));
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        std::vector<std::pair<long long, long long>> va, vb;

        cin >> n >> m;

        for (int i = 1, x; i <= n; i++) {
            cin >> a[i];
        }

        cin >> k;

        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }

        expand(a, n, m, va);
        expand(b, k, m, vb);

        cout << (va == vb ? "Yes" : "No") << endl;
    }

    return 0;
}
