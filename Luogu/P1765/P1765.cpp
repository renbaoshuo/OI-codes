// R38667223

#include <bits/stdc++.h>

using namespace std;

int num[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
//             a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v. w, x, y, z
int main() {
    char c;
    int cnt = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == ' ') {
            cnt++;
        } else if ('a' <= c && c <= 'z') {
            cnt += num[c - 'a'];
        }
        // cout << c << ' ' << cnt << endl;
    }
    cout << cnt << endl;
    return 0;
}
