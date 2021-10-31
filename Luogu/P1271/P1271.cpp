// R38787626

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[2000005];
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        cin >> a[i];
    }
    sort(a, a+m);
    for(int i = 0 ; i < m ; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
