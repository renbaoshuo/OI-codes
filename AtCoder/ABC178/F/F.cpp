#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N], b[N];
std::vector<int> v1, v2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    std::sort(a + 1, a + 1 + n, std::less<>());
    std::sort(b + 1, b + 1 + n, std::greater<>());

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) v1.emplace_back(i);
    }

    if (v1.empty()) {
        cout << "Yes" << endl;

        for (int i = 1; i <= n; i++) {
            cout << b[i] << ' ';
        }

        cout << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[v1[0]]) v2.emplace_back(i);
        else if (b[i] == a[v1[0]]) v2.emplace_back(i);
    }

    std::sort(v2.begin(), v2.end());

    int l = v2[0] - 1;
    int r = *v2.rbegin() + 1;

    for (int p : v1) {
        if (l) {
            std::swap(b[l--], b[p]);
        } else if (r <= n) {
            std::swap(b[r++], b[p]);
        } else {
            cout << "No" << endl;

            exit(0);
        }
    }

    cout << "Yes" << endl;

    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }

    cout << endl;

    return 0;
}
