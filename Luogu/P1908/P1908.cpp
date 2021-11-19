#include <bits/stdc++.h>

using namespace std;

long long n, ans, a[500005], t[500005];

void merge_sort(long long a[], long long l, long long r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid) {
        t[k++] = a[i++];
    }
    while (j <= r) {
        t[k++] = a[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++) {
        a[i] = t[j];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 1, n);
    cout << ans << endl;
    return 0;
}
