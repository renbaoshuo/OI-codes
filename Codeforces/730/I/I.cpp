#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, p, s, sum, op[N];
std::pair<int, int> a[N], b[N];
std::priority_queue<std::pair<int, int>> q1, q2, q3;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    std::sort(a + 1, a + 1 + n, [](auto a, auto b) {
        return a.first > b.first;
    });

    for (int i = 1; i <= p; i++) {
        sum += a[i].first;
        op[a[i].second] = 1;
    }

    std::sort(a + 1, a + 1 + n, [](auto a, auto b) {
        return a.second < b.second;
    });

    for (int i = 1; i <= n; i++) {
        q1.push(a[i]);
        q2.push(b[i]);
        q3.emplace(b[i].first - a[i].first, i);
    }

    for (int i = 1; i <= s; i++) {
        int val = std::numeric_limits<int>::min(),
            id1 = 0,
            id2 = 0,
            opt = 0;

        while (!q2.empty() && op[q2.top().second] != 0) q2.pop();

        if (!q2.empty() && q2.top().first > val) {
            val = q2.top().first;
            id1 = q2.top().second;
            opt = 1;
        }

        while (!q1.empty() && op[q1.top().second] != 0) q1.pop();
        while (!q3.empty() && op[q3.top().second] != 1) q3.pop();

        if (!q1.empty() && !q3.empty()) {
            int sum = q1.top().first + q3.top().first;

            if (sum > val) {
                val = sum;
                id1 = q3.top().second;
                id2 = q1.top().second;
                opt = 2;
            }
        }

        sum += val;

        if (opt == 1) {
            q2.pop();
            op[id1] = 2;
        } else {
            q1.pop();
            q3.pop();
            op[id1] = 2;
            op[id2] = 1;
            q3.emplace(b[id2].first - a[id2].first, id2);
        }
    }

    cout << sum << endl;

    for (int i = 1; i <= n; i++) {
        if (op[i] == 1) {
            cout << a[i].second << ' ';
        }
    }

    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (op[i] == 2) {
            cout << a[i].second << ' ';
        }
    }

    cout << endl;

    return 0;
}
