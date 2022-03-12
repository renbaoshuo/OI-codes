#include <iostream>
#include <map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n;
int a[N], b[N], c[N];

std::map<int, int> map;

signed main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        map[b[i]] = 1e9 + 5;
    }
    for (int i = 1; i <= n; i++) {
        char op;
        cin >> op;
        if (op == 'R') {
            map[b[i]] = std::min(map[b[i]], a[i]), c[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            if (map[b[i]] <= a[i]) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
