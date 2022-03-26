#include <iostream>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

int n;
std::set<int> set;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x > 0) set.insert(x);
    }
    cout << set.size() << endl;
    return 0;
}
