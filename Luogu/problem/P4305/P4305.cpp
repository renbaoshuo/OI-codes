#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        unordered_map<int, bool> m;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (!m[x]) {
                m[x] = true;
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}
