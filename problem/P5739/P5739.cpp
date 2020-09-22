// R38740581

#include<bits/stdc++.h>

using namespace std;

int ans[13] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main() {
    int n;
    cin >> n;
    cout << ans[n];
    return 0;
}
