#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = (18 << 1) + 5;

int n;
long long ans;
bool vis[N];
std::string s;
std::unordered_map<std::string, int> map;

void dfs1(int x) {
    if (x == n + 1) {
        std::string s1, s2;

        for (int i = 1; i <= n; i++) {
            (vis[i] ? s2 : s1).push_back(s[i]);
        }

        map[s1 + ' ' + s2]++;

        return;
    }

    dfs1(x + 1);
    vis[x] = true;
    dfs1(x + 1);
    vis[x] = false;
}

void dfs2(int x) {
    if (x == n * 2 + 1) {
        std::string s1, s2;

        for (int i = n + n; i > n; i--) {
            (vis[i] ? s2 : s1).push_back(s[i]);
        }

        ans += map[s1 + ' ' + s2];

        return;
    }

    dfs2(x + 1);
    vis[x] = true;
    dfs2(x + 1);
    vis[x] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    s = ' ' + s;

    dfs1(1);
    dfs2(n + 1);

    cout << (ans >> 1) << endl;

    return 0;
}
