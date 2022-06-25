#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, k, q, a[N];
bool s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> q;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];

        s[a[i]] = true;
    }

    while (q--) {
        int x;

        cin >> x;

        if (a[x] < n && !s[a[x] + 1]) {
            s[a[x]] = false;
            s[a[x] + 1] = true;
            a[x]++;
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;

    return 0;
}
