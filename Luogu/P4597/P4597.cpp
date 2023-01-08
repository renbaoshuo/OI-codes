#include <iostream>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n;
long long ans;
std::priority_queue<long long> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        q.emplace(x);

        if (x < q.top()) {
            ans += q.top() - x;
            q.pop();
            q.emplace(x);
        }
    }

    cout << ans << endl;

    return 0;
}
