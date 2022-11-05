#include <iostream>
#include <deque>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, m, p[N], c[N];
long long ans;
bool reversed;
std::string s;
std::deque<int> q;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        q.emplace_back(p[i]);
    }

    for (int i = n; i; i--) {
        ans += sum(p[i]);
        add(p[i], 1);
    }

    cout << ans << endl;

    cin >> s;

    for (char c : s) {
        if (c == 'S') {
            int u;

            if (reversed) {
                u = q.back();
                q.pop_back();
                q.push_front(u);
            } else {
                u = q.front();
                q.pop_front();
                q.push_back(u);
            }

            ans += (n - 2 * u + 1);
        } else {  // c == 'R'
            reversed = !reversed;
            ans = static_cast<long long>(n) * (n - 1) / 2 - ans;
        }

        cout << ans % 10;
    }

    cout << endl;

    return 0;
}
