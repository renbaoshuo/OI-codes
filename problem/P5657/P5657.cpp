#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    while ((--n) + 1) {
        if ((1ull << n) - 1 < k) {
            printf("1");
            k = (1ull << n) - k + (1ull << n) - 1;
        }
        else {
            printf("0");
        }
    }
    cout << endl;
    return 0;
}