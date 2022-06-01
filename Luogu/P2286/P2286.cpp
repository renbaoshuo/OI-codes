#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e6;

int n, op, x, ans;
std::vector<int> a, b;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op >> x;
        if (op == 0) {
            if (b.empty()) {
                a.insert(std::lower_bound(a.begin(), a.end(), -x), -x);
            } else {
                auto it = std::lower_bound(b.begin(), b.end(), -x);
                if (it == b.end() || it != b.begin() && std::abs(-*it - x) > std::abs(-*(it - 1) - x)) --it;
                ans = (ans + std::abs(-*it - x)) % mod;
                b.erase(it);
            }
        } else {  // op == 1
            if (a.empty()) {
                b.insert(std::lower_bound(b.begin(), b.end(), -x), -x);
            } else {
                auto it = std::lower_bound(a.begin(), a.end(), -x);
                if (it == a.end() || it != a.begin() && std::abs(-*it - x) > std::abs(-*(it - 1) - x)) --it;
                ans = (ans + std::abs(-*it - x)) % mod;
                a.erase(it);
            }
        }
    }
    cout << ans % mod << endl;
    return 0;
}
