#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, p[N];
long long ans;
std::priority_queue<int, std::vector<int>, std::greater<>> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!q.empty() && q.top() < p[i]) {
            ans += p[i] - q.top();
            q.pop();
            q.emplace(p[i]);
        }

        q.emplace(p[i]);
    }

    cout << ans << endl;

    return 0;
}
