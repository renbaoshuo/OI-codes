#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, ans;
std::pair<int, int> lines[N];

// 包含
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    auto(*)(std::pair<int, int>, std::pair<int, int>)->bool>
q1([](std::pair<int, int> a, std::pair<int, int> b) -> bool {
    return a.second - a.first < b.second - b.first;
});

// 相交
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    auto(*)(std::pair<int, int>, std::pair<int, int>)->bool>
q2([](std::pair<int, int> a, std::pair<int, int> b) -> bool {
    return a.first + a.second > b.first + b.second;
});

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    std::sort(lines + 1, lines + 1 + n);

    q1.push(lines[1]);
    q2.push(lines[1]);

    for (int i = 2; i <= n; i++) {
        while (!q1.empty() && lines[i].second >= q1.top().second) q1.pop();  // 剔除已经相交的线段
        while (!q2.empty() && lines[i].first >= q2.top().second) q2.pop();   // 剔除已经相离的线段

        if (!q1.empty()) {
            auto p = q1.top(),
                 q = lines[i];
            ans = std::max(ans, (p.second - p.first) - (q.second - q.first));
        }

        if (!q2.empty()) {
            auto p = q2.top(),
                 q = lines[i];
            ans = std::max(ans, (q.second - p.second) + (q.first - p.first));
        }

        q1.push(lines[i]);
        q2.push(lines[i]);
    }

    cout << ans << endl;

    return 0;
}
