#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, r, b;
std::string s;
std::vector<std::pair<int, int>> st{{0, 0}};
std::vector<std::vector<int>> ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> b >> s;

    s = ' ' + s;

    int cnt_r = std::count(s.begin(), s.end(), 'R'),
        cnt_b = std::count(s.begin(), s.end(), 'B');

    if ((n % (r + b)) || (!r && cnt_r) || (!b && cnt_b) || r && b && (cnt_r % r || cnt_b % b || cnt_r / r != cnt_b / b)) {
        cout << "NO" << endl;

        exit(EXIT_SUCCESS);
    }

    cout << "YES" << endl
         << n / (r + b) << endl;

    // Hack: 9 1 2 RBBBRRBBB
    //
    // for (int i = 1; i <= n; i++) {
    //     if (i % (r + b) == 0) {
    //         cout << i << endl;
    //     } else {
    //         cout << i << ' ';
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        st.emplace_back(i, st.back().second + (s[i] == 'R'));

        if (st.size() > r + b && st.back().second - st[st.size() - r - b - 1].second == r) {
            std::vector<int> res;

            std::for_each(st.end() - r - b, st.end(), [&](std::pair<int, int> x) { res.emplace_back(x.first); });
            st.erase(st.end() - r - b, st.end());
            ans.emplace_back(res);
        }
    }

    std::reverse(ans.begin(), ans.end());

    for (auto e : ans) {
        for (int x : e) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
