#include <bits/stdc++.h>

using namespace std;

struct node {
    int start, end;
    bool value;

    node()
        : start(-1), end(-1), value(false) {}
    node(int _start, int _end, bool _value)
        : start(_start), end(_end), value(_value) {}
};

int n, cnt;
bool a[200005], used[200005];
queue<node> q, q2;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = !a[n];
    for (int i = 2, t = 1; i <= n + 1; i++) {
        if (a[i] != a[i - 1]) {
            q.push(node(t, i - 1, a[i - 1]));
            t = i;
        }
    }
    cnt = n;
    while (cnt) {
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            while (used[t.start] && t.start <= t.end) t.start++;
            if (t.start > t.end) continue;
            cout << t.start << ' ';
            cnt--;
            used[t.start] = true;
            if (t.start == t.end) continue;
            t.start++;
            q2.push(t);
        }
        while (!q2.empty()) {
            auto t = q2.front();
            q2.pop();
            while (!q2.empty()) {
                auto x = q2.front();
                if (x.value == t.value) {
                    t.end = x.end;
                    q2.pop();
                } else {
                    break;
                }
            }
            q.push(t);
        }
        cout << endl;
    }
    return 0;
}
