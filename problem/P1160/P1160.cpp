#include <bits/stdc++.h>

using namespace std;

int n, k, p, x;
vector<int> a;
map<int, bool> m;

int main() {
    scanf("%d", &n);
    a.push_back(0);
    a.push_back(1);
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &k, &p);
        a.insert(find(a.begin(), a.end(), k) + p, i);
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        m[x] = 1;
    }
    for (vector<int>::iterator it = a.begin() + 1; it != a.end(); it++) {
        if(!m[*it]) printf("%d ", *it);
    }
    printf("\n");
    return 0;
}
