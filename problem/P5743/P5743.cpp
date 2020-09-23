// R38781374

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum;
    sum = 1;
    cin >> n;
    for (int i = n-1; i > 0; i--) {
        sum++;
        sum *= 2;
    }
    cout << sum;
    return 0;
}
