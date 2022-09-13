#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

bool is_prime(int x) {
    if (x <= 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    std::vector<int> p;

    cin >> n;

    if (is_prime(n)) {
        cout << "NO" << endl;

        exit(0);
    }

    t = n;

    for (int i = 2; i * i <= t; i++) {
        while (t % i == 0) {
            p.emplace_back(i);
            t /= i;
        }
    }

    if (t > 1) p.emplace_back(t);

    int sum = std::accumulate(p.begin(), p.end(), 0);

    cout << "YES" << endl
         << static_cast<int>(p.size()) + (n - sum) << endl;

    for (const int& x : p) {
        cout << x << ' ';
    }

    while (sum < n) {
        cout << 1 << ' ';
        sum++;
    }

    cout << endl;

    return 0;
}
