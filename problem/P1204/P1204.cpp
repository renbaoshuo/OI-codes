#include <bits/stdc++.h>

using namespace std;

struct node {
    int start, end;

    bool operator<(node b) {
        return start < b.start;
    }

    node() {
        start = end = 0;
    }
} a[5005];

int main() {
    int n, start, end, ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].end;
    }
    sort(a, a + n);
    start = a[0].start;
    end = a[0].end;
    for (int i = 1; i < n; i++) {
        if (a[i].start <= end) {
            end = max(end, a[i].end);
        }
        else {
            ans1 = max(ans1, end - start);
            ans2 = max(ans2, a[i].start - end);
            start = a[i].start;
            end = a[i].end;
        }
    }
    ans1 = max(ans1, end - start);
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
