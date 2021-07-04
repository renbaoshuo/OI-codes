// R38818108

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[5000005];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    nth_element(a, a + m, a + n);  // sort(a, a+n);
    printf("%d\n", a[m]);
    return 0;
}
