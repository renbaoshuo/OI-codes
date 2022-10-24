#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

std::pair<int, int> calc(int n, int b, int x) {
    int k = std::ceil(1.0 * x / b);
    return {n - k, x - k * b};
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m, a, b;

        cin >> n >> m >> a >> b;

        int s = b, t = a;

        while (n && m) {
            int k = std::min(
                std::ceil(static_cast<double>(s) / m),
                std::ceil(static_cast<double>(t) / n));
            int x = k * n, y = k * m;

            while (m && x >= t) {
                x -= t;
                t = a;
                m--;
            }

            while (n && y >= s) {
                y -= s;
                s = b;
                n--;
            }

            t -= x;
            s -= y;
        }

        cout << n << endl;
    }

    return 0;
}
