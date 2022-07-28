#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int n;
long long ans = std::numeric_limits<long long>::max();

void dfs(long long now, int id, int max, int cnt) {
    if (cnt > n || now <= 0 || now > ans || id > 15) return;
    if (cnt == n) {
        ans = now;
        return;
    }

    for (int i = 1; i <= max; i++) {
        dfs(now *= primes[id], id + 1, i, cnt * (i + 1));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(1, 0, 64, 1);

    cout << ans << endl;

    return 0;
}
