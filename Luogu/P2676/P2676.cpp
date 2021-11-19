// R38819026

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h[20005], b, sum = 0, i;
    cin >> n >> b;
    for (i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n);
    while (sum < b) {
        sum += h[--i];
    }
    cout << n - i << endl;
    return 0;
}
