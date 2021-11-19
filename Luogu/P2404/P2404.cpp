#include <bits/stdc++.h>

using namespace std;

int n, a[10];

void dfs(int x, int depth, int last) {
    if (x > n) return;
    if (x == n) {
        for (int i = 1; i < depth - 1; i++) {
            cout << a[i] << '+';
        }
        cout << a[depth - 1] << endl;
        return;
    }
    for (int i = last; i < n; i++) {
        a[depth] = i;
        dfs(x + i, depth + 1, i);
        a[depth] = 0;
    }
    return;
}

int main() {
    cin >> n;
    dfs(0, 1, 1);
    return 0;
}
