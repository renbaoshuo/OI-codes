#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
    cin >> n;
    while (n) {
        s = s * 10 + n % 10;
        n /= 10;
    }
    cout << s << endl;
    return 0;
}
