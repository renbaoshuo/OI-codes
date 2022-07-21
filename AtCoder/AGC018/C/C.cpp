#include <iostream>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, x, y, z;
long long pre[N], suf[N], sum, ans;

struct node {
    int a, b, c, id;
} a[N];

std::priority_queue<int> q1, q2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y >> z;

    n = x + y + z;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;

        sum += a[i].c;  // 先钦定全选铜币
        a[i].id = i;
    }

    std::sort(a + 1, a + 1 + n, [](node a, node b) {
        return a.a - a.b > b.a - b.b;
    });

    for (int i = 1; i <= n; i++) {
        q1.push(a[i].c - a[i].a);
        pre[i] = pre[i - 1] + a[i].a - a[i].c;

        if (q1.size() > x) {
            pre[i] += q1.top();
            q1.pop();
        }
    }

    for (int i = n; i; i--) {
        q2.push(a[i].c - a[i].b);
        suf[i] = suf[i + 1] + a[i].b - a[i].c;

        if (q2.size() > y) {
            suf[i] += q2.top();
            q2.pop();
        }
    }

    for (int i = x; i + y <= n; i++) {
        ans = std::max(ans, sum + pre[i] + suf[i + 1]);
    }

    cout << ans << endl;

    return 0;
}
