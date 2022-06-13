#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 1e4 + 5;

int n, a[N], b[N], lst[N];

int query1(int x) {
    char res;
    cout << "? 1 " << x << endl;
    cin >> res;
    return res - 'a' + 1;
}

int query2(int l, int r) {
    int res;
    cout << "? 2 " << l << ' ' << r << endl;
    cin >> res;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    lst[a[1] = query1(1)] = 1;

    for (int i = 2; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= 26; j++) {
            if (lst[j]) b[++cnt] = lst[j];
        }

        std::sort(b + 1, b + 1 + cnt);

        int l = 1, r = cnt, res = 0;
        while (l <= r) {
            int mid = l + r >> 1;

            if (query2(b[mid], i) == cnt - mid + 1) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        lst[a[i] = res ? a[b[res]] : query1(i)] = i;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << char(a[i] - 1 + 'a');
    }
    cout << endl;

    return 0;
}
