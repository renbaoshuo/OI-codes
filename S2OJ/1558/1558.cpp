#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, m, a[N];
long long ans;
std::unordered_set<int> set;
std::unordered_map<int, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, j = 0; i <= n - m + 1; i++) {
        while (j < n && set.size() < m) {
            set.insert(a[++j]);
            map[a[j]]++;
        }

        if (set.size() == m) ans += n - j + 1;
        if (!--map[a[i]]) set.erase(a[i]);
    }

    cout << ans << endl;

    return 0;
}
