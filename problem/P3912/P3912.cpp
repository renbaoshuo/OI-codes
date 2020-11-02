#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s = n-1;
    bool prime[100000005];
    memset(prime, 0, sizeof(prime));
    for(int i = 2 ; i*i <= n ; i++) {
        if(!prime[i]) {
            for(int j = i*2 ; j <= n ; j+= i) {
                if(!prime[j]) {
                    prime[j] = true;
                    s--;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}
