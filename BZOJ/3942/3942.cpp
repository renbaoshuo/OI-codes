#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;
const int hash = 233333;

int cnt;
char st[N];
std::string s, t;
unsigned long long p = 1, h[N], t_hash;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    s = ' ' + s;

    for (char c : t) {
        t_hash = t_hash * hash + c;
        p *= hash;
    }

    for (int i = 1; i <= n; i++) {
        st[++cnt] = s[i];

        h[cnt] = h[cnt - 1] * hash + s[i];

        if (cnt >= m && h[cnt] - h[cnt - m] * p == t_hash) {
            cnt -= m;
        }
    }

    for (int i = 1; i <= cnt; i++) {
        cout << st[i];
    }

    cout << endl;

    return 0;
}
