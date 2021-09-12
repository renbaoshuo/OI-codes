#include <bits/stdc++.h>

using namespace std;

int n, a[100005], t[100005];
long long ans;
string s;
map<string, int> m1;

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
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
        cin >> s;
        m1[s] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s;
        a[i] = m1[s];
    }
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}
