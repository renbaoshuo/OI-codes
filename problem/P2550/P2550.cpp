// https://www.luogu.com.cn/record/36172239

#include <bits/stdc++.h>

using namespace std;

int n, win[7], lottery[7], sum[10], c;

int main() {
    cin >> n;
    for(int i = 0 ; i < 7 ; i++) {
        cin >> win[i];
    }
    for(int i = 0 ; i < n ; i++) {
        c = 0;
        for(int j = 0 ; j < 7 ; j++) {
            cin >> lottery[j];
            for(int p = 0 ; p < 7 ; p++) {
                if(lottery[j] == win[p]) c++;
            }
        }
        // cout << c << ' ';  // debug
        sum[c]++;
    }
    // cout << endl;  // debug
    for(int i = 7 ; i > 0 ; i--) {
        cout << sum[i] << ' ';
    }
    return 0;
}

