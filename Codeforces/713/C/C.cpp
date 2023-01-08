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

        q.emplace(x - i);

        if (q.top() > x - i) {
            ans += q.top() - (x - i);
            q.pop();
            q.emplace(x - i);
        }
    }

    cout << ans << endl;

    return 0;
}
