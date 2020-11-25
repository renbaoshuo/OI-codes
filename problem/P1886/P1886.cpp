#include <bits/stdc++.h>

using namespace std;

struct node {
    int key, val;
} a[1000005];

int n, k;
deque<node> q;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        a[i].key = i;
        cin >> a[i].val;
    }
    // 最小值
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && a[i].val <= q.front().val) q.pop_front();
        q.push_front(a[i]);
        while (q.back().key <= i - k) q.pop_back();
        if (i >= k) cout << q.back().val << ' ';
    }
    q.clear();
    cout << endl;
    // 最大值
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && a[i].val >= q.front().val) q.pop_front();
        q.push_front(a[i]);
        while (q.back().key <= i - k) q.pop_back();
        if (i >= k) cout << q.back().val << ' ';
    }
    q.clear();
    cout << endl;
    return 0;
}
