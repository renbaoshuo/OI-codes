#include <iostream>
#include <array>
#include <fstream>
#include <set>

// using std::cin;
// using std::cout;
std::ifstream cin("lock.in");
std::ofstream cout("lock.out");
const char endl = '\n';

const int N = 10,
          M = 5;

int n, ans;
std::array<int, M> a[N];
std::set<std::array<int, M>> set_pre;

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
            ans = set_now.size();
            set_pre = set_now;
        } else {
            std::set<std::array<int, M>> set;

            for (auto o : set_pre) {
                if (set_now.count(o)) {
                    set.emplace(o);
                }
            }

            ans = set.size();
            set_pre = set;
        }
    }

    cout << ans << endl;

    return 0;
}
