#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a;
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        a.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        reverse(a.begin() + l, a.begin() + r + 1);
    }
    for (int i = 1; i < a.size(); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
