#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, c;

    cin >> t >> c;

    while (t--) {
        int n, m;

        cin >> n >> m;

        std::vector<int> s(1), t(1);
        std::unordered_map<int, int> lst_s, lst_t;

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            s.emplace_back(i - lst_s[x]);
            lst_s[x] = i;
        }

        for (int i = 1, x; i <= m; i++) {
            cin >> x;

            t.emplace_back(i - lst_t[x]);
            lst_t[x] = i;
        }

        std::vector<int> nxt(m + 1);

        for (int i = 2, j = 0; i <= m; i++) {
            while (j && t[j + 1] != std::min(t[i], j + 1)) j = nxt[j];
            if (t[j + 1] == std::min(t[i], j + 1)) j++;
            nxt[i] = j;
        }

        std::vector<int> ans;

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && t[j + 1] != std::min(s[i], j + 1)) j = nxt[j];
            if (std::min(s[i], j + 1) == t[j + 1]) j++;
            if (j == m) {
                ans.emplace_back(i - m + 1);
                j = nxt[j];
            }
        }

        cout << ans.size() << endl;

        for (int x : ans) cout << x << ' ';

        cout << endl;
    }

    return 0;
}
