#include <iostream>
#include <algorithm>
#include <array>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 22,
          M = 105;
const int INF = 0x3f3f3f3f;

int n, m;
std::array<int, M> a, b1, b2, f1, f2;
std::array<int, 1 << N> dist;
std::array<bool, 1 << N> vis;

bool check(int s, int i) {
    if ((b1[i] | s) != s) return false;
    if (b2[i] & s) return false;

    return true;
}

void spfa(int s) {
    std::fill(dist.begin(), dist.end(), INF);

    std::queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= m; i++) {
            if (!check(u, i)) continue;

            int v = u ^ (u & f1[i]) | f2[i];

            if (dist[u] + a[i] < dist[v]) {
                dist[v] = dist[u] + a[i];

                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        vis[u] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        std::string b, f;

        cin >> a[i] >> b >> f;

        for (int j = 0; j < b.size(); j++) {
            if (b[j] == '+') {
                b1[i] = b1[i] | 1 << j;
            } else if (b[j] == '-') {
                b2[i] = b2[i] | 1 << j;
            }
        }

        for (int j = 0; j < f.size(); j++) {
            if (f[j] == '-') {
                f1[i] = f1[i] | 1 << j;
            } else if (f[j] == '+') {
                f2[i] = f2[i] | 1 << j;
            }
        }
    }

    spfa((1 << n) - 1);

    cout << (dist[0] == INF ? 0 : dist[0]) << endl;

    return 0;
}
