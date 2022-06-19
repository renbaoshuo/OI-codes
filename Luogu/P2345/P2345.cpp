#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int n;
long long ans;
std::pair<int, int> p[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            ans += 1ll * std::max(p[i].first, p[j].first) * std::abs(p[i].second - p[j].second);
        }
    }

    cout << ans << endl;

    return 0;
}
