// R38821808

#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y, z;

    node() {
        x = y = z = 0;
    }
};

double ed(node a, node b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

bool cmp(node a, node b) {
    return a.z <= b.z;
}

int main() {
    int n;
    node a[50005];
    double ans = 0.000;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a, a+n, cmp);
    for(int i = 1 ; i < n ;i++) {
        ans += ed(a[i-1], a[i]);
    }
    printf("%.3lf", ans);
    return 0;
}
