#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, d, t, ans = 0;
    scanf("%d-%d", &m, &d);
    if (1 <= m && m <= 12) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            t = 31;
        } else if (m == 2) {
            t = 28;
        } else {
            t = 30;
        }
        if (1 <= d && d <= t) {
            ans = 0;
        } else {
            ans = 1;
        }
    } else if (12 < m && m < 20) {
        if (1 <= d && d <= 31) {
            ans = 1;
        } else {
            ans = 2;
        }
    } else {
        if (m % 10 == 1 || m % 10 == 2 || m % 10 == 3 || m % 10 == 5 || m % 10 == 7 || m % 10 == 8) {
            t = 31;
        } else {
            t = 30;
        }
        if (1 <= d && d <= t) {
            ans = 1;
        } else {
            ans = 2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
