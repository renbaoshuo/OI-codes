#include <iostream>
#include <map>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m;
std::map<int, int> a;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if (!a[x]--) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
