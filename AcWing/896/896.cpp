#include <bits/stdc++.h>

using namespace std;

int n, a[100005], q[100005], len;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    q[0] = 0xc0c0c0c0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (q[mid] < a[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        q[l] = a[i];
        len = max(len, l);
    }
    cout << len << endl;
    return 0;
}
