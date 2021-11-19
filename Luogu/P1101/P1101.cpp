#include <bits/stdc++.h>

using namespace std;

int n;
int u[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int v[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool vis[101][101];
string s[105];
map<char, char> wd;

bool dfs(int x, int y, char w, int p) {
    if (w == 'g') {
        return vis[x][y] = true;
    }
    int xx = x + u[p], yy = y + v[p];
    if (xx >= 0 && yy >= 0 && xx < n && yy < n && s[xx][yy] == wd[w]) {
        if (dfs(xx, yy, wd[w], p)) {
            return vis[x][y] = true;
        }
    }
    return false;
}

int main() {
    wd['y'] = 'i';
    wd['i'] = 'z';
    wd['z'] = 'h';
    wd['h'] = 'o';
    wd['o'] = 'n';
    wd['n'] = 'g';
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'y') {
                for (int k = 0; k < 8; k++) {
                    if (dfs(i, j, 'y', k)) {
                        vis[i][j] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                s[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
