#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int Q = 1e5 + 5;
const int mod = 1e7 + 19;

int n, q, t, inv[mod], add, mul = 1, sum, ans;
std::tuple<int, int, int> ops[Q];
std::unordered_map<int, int> map;

int get(int x) {
    return (static_cast<long long>(map.count(x) ? map[x] : 0) * mul + add) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inv[1] = 1;
    for (int i = 2; i < mod; i++) {
        inv[i] = static_cast<long long>(mod - mod / i) * inv[mod % i] % mod;
    }

    cin >> n >> q;

    for (int i = 1, x, v; i <= q; i++) {
        cin >> x;

        std::get<0>(ops[i]) = x;

        if (x == 1) {
            cin >> std::get<1>(ops[i]) >> v;

            std::get<2>(ops[i]) = (v % mod + mod) % mod;
        } else if (x <= 5) {
            cin >> v;

            std::get<1>(ops[i]) = (v % mod + mod) % mod;
        }

        if (x == 3 && std::get<1>(ops[i]) == 0) {
            std::get<0>(ops[i]) = 4;
        }
    }

    cin >> t;

    for (int i = 1, a, b; i <= t; i++) {
        cin >> a >> b;

        for (int j = 1; j <= q; j++) {
            int id = (a + static_cast<long long>(j) * b) % q + 1;
            int op = std::get<0>(ops[id]);

            if (op == 1) {
                int index = std::get<1>(ops[id]),
                    value = std::get<2>(ops[id]);

                sum = ((sum - get(index)) % mod + mod) % mod;
                map[index] = (static_cast<long long>(value - add) * inv[mul] % mod + mod) % mod;
                sum = ((sum + value) % mod + mod) % mod;
            } else if (op == 2) {
                int value = std::get<1>(ops[id]);

                add = ((add + value) % mod + mod) % mod;
                sum = ((sum + static_cast<long long>(value) * n % mod) % mod + mod) % mod;
            } else if (op == 3) {
                int value = std::get<1>(ops[id]);

                mul = (static_cast<long long>(mul) * value % mod + mod) % mod;
                add = (static_cast<long long>(add) * value % mod + mod) % mod;
                sum = (static_cast<long long>(sum) * value % mod + mod) % mod;
            } else if (op == 4) {
                int value = std::get<1>(ops[id]);

                mul = 1;
                add = value;
                sum = (static_cast<long long>(value) * n % mod + mod) % mod;
                map.clear();
            } else if (op == 5) {
                int index = std::get<1>(ops[id]);

                ans = ((ans + get(index)) % mod + mod) % mod;
            } else {  // op == 6
                ans = ((ans + sum) % mod + mod) % mod;
            }
        }
    }

    cout << (ans % mod + mod) % mod << endl;

    return 0;
}
