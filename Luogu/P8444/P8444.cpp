#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n;
long long w;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    std::vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    std::sort(a.begin(), a.end());

    cin >> w;

    auto it = std::upper_bound(a.begin(), a.end(), w);

    if (it == a.begin()) {
        cout << 0 << endl;

        exit(0);
    } else {
        it--;
    }

    int ans = 0;
    long long sum = 0;
    for (auto i = a.begin(); i != a.end(); i++) {
        if ((sum += *i) <= *it) ans++;
        else break;
    }

    cout << ans << endl;

    return 0;
}
