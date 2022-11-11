// #include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <utility>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("original.in");
std::ofstream cout("original.out");
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, p;
    std::vector<std::pair<long long, int>> res;

    cin >> n >> p;

    for (long long i = 2; std::pow(i, 3) <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            p = p / (i - 1) * i;

            while (n % i == 0) {
                n /= i;
                cnt++;
                p /= i;
            }

            res.emplace_back(i, cnt);
        }
    }

    if (n == 1) {
    } else if (p == n - 1) {
        res.emplace_back(n, 1);
    } else if (std::pow(n - p, 2) == n) {
        res.emplace_back(n - p, 2);
    } else {
        long long a = n - 1 - p,
                  delta = sqrt(a * a - 4 * p);
        res.emplace_back((a - delta) / 2 + 1, 1);
        res.emplace_back((a + delta) / 2 + 1, 1);
    }

    for (auto e : res) {
        while (e.second--) {
            cout << e.first << endl;
        }
    }

    return 0;
}
