#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int expire, value;

    const bool operator<(const node& b) const {
        return expire > b.expire;
    }
} a[10005];

int main() {
    int n;
    while (cin >> n) {
        int d = 1, ans = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> a[i].value >> a[i].expire;
        }
        sort(a, a + n);
        a[n].value = a[n].expire = 0;
        for (int i = 0; i < n;) {
            int last = a[i].expire;
            while (a[i].expire == last) {
                q.push(a[i++].value);
            }
            int lim = last - a[i].expire;
            while (q.size() && lim) {
                ans += q.top();
                q.pop();
                lim--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
