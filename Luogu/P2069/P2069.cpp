#include <bits/stdc++.h>

using namespace std;

int n, m, k = 1, t;
vector<int> listnode;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        listnode.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        t = i * i * i % 5 + 1;
        k += t;
        if (k > listnode.size()) {
            k = t + 1;
        }
        if (i != m) {
            listnode.erase(listnode.begin() + k - 1);
        }
    }
    cout << listnode[k - 1] << endl;
    return 0;
}
