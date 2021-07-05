#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
bool vis[25][25][25];
int ta, tb, tc;

void dfs(int a, int b, int c) {
    if (vis[a][b][c]) return;
    if (a == 0) ans.push_back(c);
    vis[a][b][c] = true;
    if (c) {
        if (a < ta) {
            dfs(min(ta, a + c), b, c - (min(ta, a + c) - a));
        }
        if (b < tb) {
            dfs(a, min(b + c, tb), c - (min(tb, b + c) - b));
        }
    }
    if (b) {
        if (a < ta) {
            dfs(min(ta, a + b), b - (min(ta, a + b) - a), c);
        }
        if (c < tc) {
            dfs(a, b - (min(tc, c + b) - c), min(tc, c + b));
        }
    }
    if (a) {
        if (b < tb) {
            dfs(a - (min(tb, a + b) - b), min(tb, a + b), c);
        }
        if (c < tc) {
            dfs(a - (min(tc, a + c) - c), b, min(tc, c + a));
        }
    }
}

int main() {
    cin >> ta >> tb >> tc;
    clog << 1 << endl;
    dfs(0, 0, tc);
    clog << 2 << endl;
    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << endl;
    return 0;
}
