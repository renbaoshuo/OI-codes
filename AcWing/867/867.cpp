#include <bits/stdc++.h>

using namespace std;

int n, a;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                int s = 0;
                while (a % i == 0) {
                    a /= i;
                    s++;
                }
                cout << i << ' ' << s << endl;
            }
        }
        if (a > 1) {
            cout << a << ' ' << 1 << endl;
        }
        cout << endl;
    }
    return 0;
}
