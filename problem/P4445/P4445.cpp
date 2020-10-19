#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100005];
    long long ans=0;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(int i = 1 ; i < n ; i++) {
        ans += max(a[i], a[i-1]);
    }
    cout << ans << endl;
    return 0;
}
