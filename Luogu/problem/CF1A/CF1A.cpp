// R38986370

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, n, m;
    cin >> n >> m >> a;
    cout << (long long)(ceil(n / (double)a) * ceil(m / (double)a)) << endl;
    return 0;
}
