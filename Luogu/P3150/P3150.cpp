#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t % 2 == 0) {
            cout << "pb wins" << endl;
        } else {
            cout << "zs wins" << endl;
        }
    }
    return 0;
}
