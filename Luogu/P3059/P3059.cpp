#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;
const int hash = 1000003;
const int mod = 1e9 + 7;

int k, n, a[15][N], s[15][N], e[N], next[15][N], ans;
std::vector<int> nums, p[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;

    for (int i = 1; i <= k; i++) {
        std::string str;

        cin >> str;

        for (int j = 1; j <= n; j++) {
            a[i][j] = str[j - 1] == '(' ? 1 : -1;
            s[i][j] = s[i][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            e[i] = ((static_cast<long long>(e[i]) * hash % mod + s[j][i]) % mod + mod) % mod;
        }

        nums.push_back(e[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    p[0].emplace_back(0);

    for (int i = 1; i <= n; i++) {
        e[i] = std::lower_bound(nums.begin(), nums.end(), e[i]) - nums.begin() + 1;
        p[e[i]].emplace_back(i);
    }

    for (int i = 1; i <= k; i++) {
        std::stack<int> st;

        for (int j = 1; j <= n; j++) {
            while (!st.empty() && s[i][st.top()] > s[i][j]) {
                next[i][st.top()] = j;
                st.pop();
            }

            st.emplace(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        int min = n;

        for (int j = 1; j <= k; j++) {
            if (next[j][i]) {
                min = std::min(min, next[j][i]);
            }
        }

        ans += std::upper_bound(p[e[i]].begin(), p[e[i]].end(), min) - std::lower_bound(p[e[i]].begin(), p[e[i]].end(), i + 1);
    }

    cout << ans << endl;

    return 0;
}
