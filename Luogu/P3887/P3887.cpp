#include <iostream>
#include <iomanip>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

int k, d, m, f, q;
std::priority_queue<int> q_k, q_d, q_m, q_f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> d >> m >> f;

    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        q_k.emplace(x);  // 入堆
    }

    for (int i = 1, x; i <= d; i++) {
        cin >> x;
        q_d.emplace(x);
    }

    for (int i = 1, x; i <= m; i++) {
        cin >> x;
        q_m.emplace(x);
    }

    for (int i = 1, x; i <= f; i++) {
        cin >> x;
        q_f.emplace(x);
    }

    cin >> q;

    while (q--) {
        int a, b, c;

        cin >> a >> b >> c;

        int sum = 0;

        sum += q_k.top();  // 取堆顶元素（最大值）
        q_k.pop();

        for (int i = 1; i <= a; i++) {
            sum += q_d.top();
            q_d.pop();
        }

        for (int i = 1; i <= b; i++) {
            sum += q_m.top();
            q_m.pop();
        }

        for (int i = 1; i <= c; i++) {
            sum += q_f.top();
            q_f.pop();
        }

        cout << std::fixed << std::setprecision(2) << static_cast<double>(sum) / (a + b + c + 1) << endl;
    }

    return 0;
}
