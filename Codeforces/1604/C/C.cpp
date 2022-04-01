#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005];

int main() {
    scanf("%d", &t);
    while (t--) {
        bool flag = true;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            bool t = false;
            for (int j = 2; j <= i + 1; j++) {
                if (a[i] % j) {
                    t = true;
                    break;
                }
            }
            if (!t) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
