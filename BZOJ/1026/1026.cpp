#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15;

int a, b, f[N][N];

std::vector<int> gen(int x) {
    std::vector<int> res;

    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }

    return res;
}

int calc(int x) {
    int res = 0;
    auto num = gen(x);

    for (int i = 1; i < num.size(); i++) {
        for (int j = 1; j < 10; j++) {
            res += f[i][j];
        }
    }

    for (int i = 1; i < *num.rbegin(); i++) {
        res += f[num.size()][i];
    }

    for (int i = num.size() - 1; i; i--) {
        for (int j = 0; j < num[i - 1]; j++) {
            if (std::abs(j - num[i]) >= 2) {
                res += f[i][j];
            }
        }

        if (std::abs(num[i] - num[i - 1]) < 2) break;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    for (int i = 0; i < 10; i++) {
        f[1][i] = 1;
    }

    for (int i = 2; i <= 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (std::abs(j - k) >= 2) {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }

    cout << calc(b + 1) - calc(a) << endl;

    return 0;
}
