#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n;
std::string g[N];

bool check(int x, int y) {
    if (x + 5 < n) {
        int cnt = 0;
        for (int i = x; i <= x + 5; i++) {
            if (g[i][y] == '.') cnt++;
        }
        if (cnt <= 2) return true;
    }
    if (y + 5 < n) {
        int cnt = 0;
        for (int i = y; i <= y + 5; i++) {
            if (g[x][i] == '.') cnt++;
        }
        if (cnt <= 2) return true;
    }
    if (x + 5 < n && y + 5 < n) {
        int cnt = 0;
        for (int i = 0; i <= 5; i++) {
            if (g[x + i][y + i] == '.') cnt++;
        }
        if (cnt <= 2) return true;
    }
    if (x + 5 < n && y - 5 >= 0) {
        int cnt = 0;
        for (int i = 0; i <= 5; i++) {
            if (g[x + i][y - i] == '.') cnt++;
        }
        if (cnt <= 2) return true;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
