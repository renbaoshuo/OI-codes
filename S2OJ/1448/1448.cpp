#include <iostream>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m;
std::set<int> set;

int main() {
    cin >> n >> m;

    set.insert(0);
    set.insert(n);

    while (m--) {
        int k;

        cin >> k;

        set.insert(k);

        int prev = *--set.lower_bound(k),
            next = *set.upper_bound(k);

        cout << (k - prev) * (next - k) << endl;
    }

    return 0;
}
