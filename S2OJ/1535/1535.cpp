#include <iostream>
#include <deque>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n, a[N], b[N], ans;
std::deque<int> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        while (!q.empty() && b[i] >= b[q.front()]) q.pop_front();
        q.push_front(i);
    }

    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.back() <= i) q.pop_back();
        if (!q.empty()) ans = std::max(ans, b[q.back()] - a[i]);
    }

    cout << ans << endl;

    return 0;
}
