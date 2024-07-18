#include <iostream>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, v[N];
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>>
    q[N];

bool assign(int now_time, int id, int use_time, int use) {
    // 移除已经完成的任务，释放资源。一定要判非空！
    while (!q[id].empty() && q[id].top().first <= now_time) {
        v[id] += q[id].top().second;
        q[id].pop();
    }

    if (v[id] < use) {  // 算力不足
        return false;   // 分配失败
    }

    v[id] -= use;
    q[id].emplace(now_time + use_time, use);

    return true;  // 成功
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    while (m--) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        if (assign(a, b, c, d)) {
            cout << v[b] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
