#include <bits/stdc++.h>

using namespace std;

vector<int> listnode;

int main() {
    int n, m, k = 1;
    listnode.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        listnode.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int t = i * i * i % 5 + 1;
        k += t;
        if (k > listnode.size()) {
            k = t + 1;
        }
        if (i != m) {
            listnode.erase(listnode.begin() + k - 1);
        }
    }
    cout << listnode[k] << endl;
    return 0;
}
