#include <algorithm>
#include <fstream>
#include <utility>

std::ifstream cin("number.in");
std::ofstream cout("number.out");
const char endl = '\n';

int t, x, ans[200005];
bool f[10000005];
std::pair<int, int> q[200005];

bool has7(int x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }

    return false;
}

int main() {
    cin >> t;

    for (int i = 7; i <= 10000000; i += 7) {
        f[i] = true;
    }

    for (int i = 1; i <= 10000000; i++) {
        if (has7(i)) {
            for (int j = 1; i * j <= 10000000; j++) {
                f[i * j] = true;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    std::sort(q, q + t);

    for (int i = 0, j = 1; i < t; i++) {
        if (f[q[i].first]) {
            ans[q[i].second] = -1;
            continue;
        }
        while (j <= q[i].first) j++;
        while (j <= 10000000 && f[j]) j++;
        ans[q[i].second] = j;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
