#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], b[N];
long long ans;
std::priority_queue<int> q1, q2;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        ans += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];

        (!(i & 1) ? q1 : q2).push(b[i] - a[i]);
    }

    while (!q1.empty()) {
        int t = q1.top() + q2.top();
        q1.pop(), q2.pop();

        if (t <= 0) break;
        ans += t;
    }

    cout << ans << endl;

    return 0;
}
