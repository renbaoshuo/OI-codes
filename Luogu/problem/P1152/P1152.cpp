// R38820772

#include<bits/stdc++.h>

using namespace std;

bool cnt[10000005];
int n, a[1005];

int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >>a[i];
    }
    for(int i = 1 ; i < n ; i++) {
        if(!cnt[abs(a[i]-a[i-1])]) {
            cnt[abs(a[i]-a[i-1])] = true;
        } else {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}
