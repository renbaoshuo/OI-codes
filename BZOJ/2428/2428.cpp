#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <random>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    double ans = 1e9;
    std::mt19937 rng(std::random_device{}());

    cin >> n >> m;

    std::vector<int> a(n);

    for (int& x : a) cin >> x;

    for (int i = 0; i < 1000000; i++) {
        std::vector<int> b(m);

        std::shuffle(a.begin(), a.end(), rng);

        for (int x : a) {
            *std::min_element(b.begin(), b.end()) += x;
        }

        double avg = static_cast<double>(std::accumulate(b.begin(), b.end(), 0)) / m;
        double variance = std::sqrt(std::accumulate(b.begin(), b.end(), 0.0, [&](double sum, int x) { return sum + std::pow(avg - x, 2); }) / m);

        ans = std::min(ans, variance);
    }

    cout << std::fixed << std::setprecision(2) << ans << endl;

    return 0;
}
