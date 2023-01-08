#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n;
long long a[N], b[N], ans;
std::priority_queue<long long> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        a[i] -= i;
    }

    for (int i = 1; i <= n; i++) {
        q.emplace(a[i]);

        if (q.top() > a[i]) {
            ans += q.top() - a[i];
            q.pop();
            q.emplace(a[i]);
        }

        b[i] = q.top();
    }

    for (int i = n - 1; i; i--) {
        b[i] = std::min(b[i], b[i + 1]);
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        cout << b[i] + i << ' ';
    }

    cout << endl;

    return 0;
}
