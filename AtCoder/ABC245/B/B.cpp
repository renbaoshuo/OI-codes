#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n;
bool vis[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        vis[x] = true;
    }
    for (int i = 0; i <= 2000; i++) {
        if (!vis[i]) {
            cout << i << endl;
            exit(0);
        }
    }
    return 0;
}
