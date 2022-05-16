#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, b, a[N], pos[N], st[N], ed[N], add[N];

void change(int l, int r, int d) {
    int p = pos[l], q = pos[r];

    if (p == q) {
        for (int i = l; i <= r; i++) {
            a[i] += d;
        }

        return;
    }

    for (int i = p + 1; i <= q - 1; i++) add[i] += d;
    for (int i = l; i <= ed[p]; i++) a[i] += d;
    for (int i = st[q]; i <= r; i++) a[i] += d;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    b = std::sqrt(n);
    for (int i = 1; i <= b; i++) {
        st[i] = (i - 1) * b + 1;
        ed[i] = i * b;
    }
    if (ed[b] < n) {
        b++;
        st[b] = ed[b - 1] + 1;
        ed[b] = n;
    }

    for (int i = 1; i <= b; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, op, l, r, d; i <= n; i++) {
        cin >> op >> l >> r >> d;

        if (op == 0) {
            change(l, r, d);
        } else {  // op == 1
            cout << a[r] + add[pos[r]] << endl;
        }
    }

    return 0;
}
