#include <iostream>
#include <algorithm>
#include <array>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10,
          M = 5;

int n, ans;
std::array<int, M> a[N];
std::set<std::array<int, M>> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        std::set<std::array<int, M>> set_now;

        // Type 1: Only one element is different.
        for (int j = 0; j < M; j++) {
            std::array<int, M> t = a[i];

            for (int k = 0; k < 10; k++) {
                t[j] = (a[i][j] + k) % 10;

                if (t[j] != a[i][j]) {
                    set_now.emplace(t);
                }
            }
        }

        // Type 2: Two adjacent elements are different.
        for (int j = 0; j + 1 < M; j++) {
            std::array<int, M> t = a[i];

            for (int k = 0; k < 10; k++) {
                t[j] = (a[i][j] + k) % 10;
                t[j + 1] = (a[i][j + 1] + k) % 10;

                if (t[j] != a[i][j]) {
                    set_now.emplace(t);
                }
            }
        }

        if (i == 1) {
            set = set_now;
        } else {
            std::set<std::array<int, M>> set_tmp;

            std::set_intersection(set.begin(), set.end(), set_now.begin(), set_now.end(), std::inserter(set_tmp, set_tmp.begin()));

            set = set_tmp;
        }

        ans = set.size();
    }

    cout << ans << endl;

    return 0;
}
