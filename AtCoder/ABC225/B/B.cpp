#include <bits/stdc++.h>

using namespace std;

int n, a, b;
vector<int> g[100005];

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == n - 1) {
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
    return 0;
}
