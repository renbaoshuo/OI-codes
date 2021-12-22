#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int n;
long long ans;
char c;
std::vector<int> g, h;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    g.push_back(0);
    h.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == 'G') {
            g.push_back(i);
        } else {
            h.push_back(i);
        }
    }
    g.push_back(n + 1);
    h.push_back(n + 1);
    for (int i = 1; i < h.size() - 1; i++) {
        ans += 1ll * (h[i] - h[i - 1]) * (h[i + 1] - h[i]) - 3;
        if (h[i] == h[i - 1] + 1) ans++;
        if (h[i] == h[i + 1] - 1) ans++;
    }
    for (int i = 1; i < g.size() - 1; i++) {
        ans += 1ll * (g[i] - g[i - 1]) * (g[i + 1] - g[i]) - 3;
        if (g[i] == g[i - 1] + 1) ans++;
        if (g[i] == g[i + 1] - 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
