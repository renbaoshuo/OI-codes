#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long ans = 0;
    std::vector<int> a;

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        if (x > 0) {
            ans += x;
        } else {
            a.emplace_back(x);
        }
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i & 1) sum1 += a[i];
        else sum2 += a[i];
    }

    if (a.size() == n) cout << std::max(sum1 + a[0], sum2) << endl;
    else cout << ans + std::max(sum1, sum2) << endl;

    return 0;
}
