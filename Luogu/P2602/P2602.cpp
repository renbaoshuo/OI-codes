#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

long long a, b,
    f[15], g[15]{1},
    cnt_a[10], cnt_b[10];

std::vector<int> gen(long long x) {
    std::vector<int> res;

    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }

    return res;
}

void calc(long long x, long long* r) {
    auto num = gen(x);

    for (int i = num.size(); i; i--) {
        for (int j = 0; j < 10; j++) {
            r[j] += f[i - 1] * num.at(i - 1);
        }

        for (int j = 0; j < num[i - 1]; j++) {
            r[j] += g[i - 1];
        }

        x -= g[i - 1] * num[i - 1];
        r[num[i - 1]] += x + 1;
        r[0] -= g[i - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    for (int i = 1; i <= 12; i++) {
        f[i] = f[i - 1] * 10 + g[i - 1];
        g[i] = g[i - 1] * 10;
    }

    calc(a - 1, cnt_a);
    calc(b, cnt_b);

    for (int i = 0; i < 10; i++) {
        cout << cnt_b[i] - cnt_a[i] << ' ';
    }

    cout << endl;

    return 0;
}
