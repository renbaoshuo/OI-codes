#include <bits/stdc++.h>

using namespace std;

int main() {
    int                   n, t;
    queue<pair<int, int>> q;
    cin >> n;
    n = 1 << n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        q.push(make_pair(t, i));
    }
    while (q.size() > 2) {
        pair<int, int> x, y;
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        q.push(x.first > y.first ? x : y);
    }
    pair<int, int> x, y;
    x = q.front();
    q.pop();
    y = q.front();
    q.pop();
    cout << (x.first > y.first ? y.second : x.second) << endl;
    return 0;
}
