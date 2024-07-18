#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long ans;
std::pair<int, int> a[N];  // <time, money>
std::priority_queue<int, std::vector<int>, std::greater<>> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        // 时间充足（每项工作消耗 1 个单位时间）
        if (a[i].first > q.size()) {
            q.emplace(a[i].second);  // 记录报酬
            ans += a[i].second;
        } else if (a[i].second > q.top()) {  // 时间不足，并且报酬更高

            // 推掉旧工作
            ans -= q.top();
            q.pop();

            // 做新的工作
            q.emplace(a[i].second);
            ans += a[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}
