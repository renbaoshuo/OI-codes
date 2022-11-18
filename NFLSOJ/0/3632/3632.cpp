#include <iostream>
#include <fstream>
#include <map>
#include <numeric>

// using std::cin;
// using std::cout;
std::ifstream cin("segment.in");
std::ofstream cout("segment.out");
const char endl = '\n';

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

int n;
long long a[N], s[N], f[N], sum;
std::map<long long, long long> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::partial_sum(a + 1, a + 1 + n, s + 1);

    f[0] = sum = 1;

    for (int i = 1; i <= n; i++) {
        f[i] = sum;
        sum = ((sum + f[i] - map[s[i]]) % mod + mod) % mod;
        map[s[i]] = f[i];
    }

    cout << f[n] << endl;

    return 0;
}
