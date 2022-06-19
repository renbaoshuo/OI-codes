#include <iostream>
#include <deque>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1000005;

int n, q, k, d[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    cin >> q;

    while (q--) {
        cin >> k;

        std::vector<int> f(n + 1);
        std::deque<int> q;

        q.push_back(1);
        for (int i = 2; i <= n; i++) {
            while (!q.empty() && q.front() < i - k) q.pop_front();
            f[i] = f[q.front()] + (d[q.front()] <= d[i]);
            while (!q.empty()
                   && (f[q.back()] > f[i]
                       || f[q.back()] == f[i] && d[q.back()] <= d[i]))
                q.pop_back();
            q.push_back(i);
        }

        cout << f[n] << endl;
    }

    return 0;
}
