#include <algorithm>
#include <iostream>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20;

int n, max, ans;
std::tuple<int, int, int> a[N];

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

bool check(int k) {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int c1, p1, l1, c2, p2, l2;
            std::tie(c1, p1, l1) = a[i];
            std::tie(c2, p2, l2) = a[j];

            int a = p1 - p2,
                b = k,
                c = c2 - c1;

            int x, y,
                g = exgcd(a, b, x, y);

            if (c % g) continue;

            a /= g, b = std::abs(b / g), c /= g;
            x = (x * c % b + b) % b;

            if (x <= std::min(l1, l2)) return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, c, p, l; i <= n; i++) {
        cin >> std::get<0>(a[i]) >> std::get<1>(a[i]) >> std::get<2>(a[i]);

        max = std::max(max, std::get<0>(a[i]));
    }

    for (int i = max; i <= 1000000; i++) {
        if (check(i)) {
            cout << i << endl;

            exit(0);
        }
    }

    return 0;
}
