#include <bits/stdc++.h>

using namespace std;

int x;

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> x;
        cout << "X[" << i << "] = " << (x <= 0 ? 1 : x) << endl;
    }

    return 0;
}
