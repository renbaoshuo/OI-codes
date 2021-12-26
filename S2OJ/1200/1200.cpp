#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const long long mod = 281474976710656;

int n;
long long ans;
char g[505][505];

void dfs1(int, int, std::vector<int>);
long long dfs2(int, int, std::vector<int>, int, int, std::vector<int>);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] + 1;
    }
    dfs1(1, 1, std::vector<int>());
    cout << ans << endl;
    return 0;
}

void dfs1(int x, int y, std::vector<int> s) {
    if (x < 1 || x > n || y < 1 || y > n) return;
    s.push_back(g[x][y] - 'A');
    if (x + y == n + 1) {
        ans = (ans + dfs2(n, n, std::vector<int>(), x, y, s)) % mod;
        return;
    }
    dfs1(x + 1, y, s);
    dfs1(x, y + 1, s);
}

long long dfs2(
    int x,
    int y,
    std::vector<int> s,
    int lx,
    int ly,
    std::vector<int> t) {
    if (x < lx || x > n || y < ly || y > n) return 0;
    s.push_back(g[x][y] - 'A');
    long long res = 0;
    if (x == lx && y == ly && s == t) return 1;
    res += dfs2(x - 1, y, s, lx, ly, t);
    res += dfs2(x, y - 1, s, lx, ly, t);
    return res;
}
