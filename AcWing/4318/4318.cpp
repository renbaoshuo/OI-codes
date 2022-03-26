#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int to[5][2] = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int x, y;
std::string s;
std::map<int, std::map<int, bool>> vis;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s;
    vis[x][y] = true;
    for (char c : s) {
        int xx = 0, yy = 0;
        if (c == 'U') {
            y--;
            yy--;
        } else if (c == 'D') {
            y++;
            yy++;
        } else if (c == 'L') {
            x--;
            xx--;
        } else if (c == 'R') {
            x++;
            xx++;
        }

        if (vis[x][y]) {
            cout << "NO" << endl;
            exit(0);
        }

        vis[x][y] = true;
        for (int i = 1; i <= 4; i++) {
            vis[x + to[i][0] - xx][y + to[i][1] - yy] = true;
        }
    }
    cout << "YES" << endl;
    return 0;
}
