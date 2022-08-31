#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, k;
long long m, sum;
std::pair<long long, long long> a[N];
std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + n + 1, [](auto a, auto b) {
        return a.second < b.second;
    });

    for (int i = 1; i <= k; i++) {
        sum += a[i].second;

        q.push(a[i].first - a[i].second);

        if (sum > m) {
            cout << i - 1 << endl;

            exit(0);
        } else if (i == n) {
            cout << n << endl;

            exit(0);
        }
    }

    std::sort(a + k + 1, a + n + 1, [](auto a, auto b) {
        return a.first < b.first;
    });

    for (int i = k + 1; i <= n; i++) {
        auto x = q.top();

        sum += a[i].first;

        if (a[i].second + x < a[i].first) {
            q.pop();

            auto y = a[i].first - a[i].second;
            q.push(y);
            sum += x - y;
        }

        if (sum > m) {
            cout << i - 1 << endl;

            exit(0);
        }
    }

    cout << n << endl;

    return 0;
}
