#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, d, t;
std::vector<int> u[100005];
std::pair<__int128, __int128> ans[100005];

std::ostream& operator<<(std::ostream& __ostream, __int128 __n) {
    std::string __o;

    while (__n) {
        __o.push_back(__n % 10 + '0');
        __n /= 10;
    }

    std::reverse(__o.begin(), __o.end());

    return __ostream << __o;
}

__int128 gcd(__int128 a, __int128 b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int x, __int128 first, __int128 second) {
    if (u[x].empty()) {
        if (ans[x].first && ans[x].second) {
            if (ans[x].second == second) {
                ans[x].first += first;
                __int128 tmp = gcd(ans[x].first, ans[x].second);
                ans[x].first /= tmp;
                ans[x].second /= tmp;
            } else {
                first *= ans[x].second;
                ans[x].first *= second;
                ans[x].first += first;
                ans[x].second *= second;
                __int128 tmp = gcd(ans[x].first, ans[x].second);
                ans[x].first /= tmp;
                ans[x].second /= tmp;
            }
        } else {
            ans[x].first = first;
            ans[x].second = second;
        }

        return;
    }

    int s = u[x].size();
    second *= s;

    for (int i = 0; i < s; i++) {
        dfs(u[x][i], first, second);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> d;
        for (int j = 1; j <= d; j++) {
            cin >> t;
            u[i].emplace_back(t);
        }
    }

    for (int i = 1; i <= m; i++) {
        dfs(i, 1, 1);
    }

    for (int i = 1; i <= n; i++) {
        if (u[i].empty()) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }

    return 0;
}
