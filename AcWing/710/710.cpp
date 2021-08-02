#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    for (int i = x; i <= x + 11; i++) {
        if (i & 1) cout << i << endl;
    }
    return 0;
}
