#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, min, k, c, cnt;
char op;
std::vector<int> a;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> min;
    while (n--) {
        cin >> op >> k;
        if (op == 'I') {
            if (k >= min) {
                a.insert(std::lower_bound(a.begin(), a.end(), k - c), k - c);
            }
        } else if (op == 'A') {
            c += k;
        } else if (op == 'S') {
            c -= k;
            auto it = std::lower_bound(a.begin(), a.end(), min - c);
            cnt += it - a.begin();
            a.erase(a.begin(), std::lower_bound(a.begin(), a.end(), min - c));
        } else {  // op == 'F'
            cout << (a.size() < k ? -1 : *(a.end() - k) + c) << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}
