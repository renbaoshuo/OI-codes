// R38704401

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a[2], n;
    scanf("%lld%lld%lld", &a[0], &a[1], &n);
    cout << n * a[0] + n * (n - 1) * (a[1] - a[0]) / 2 << endl;
    return 0;
}
