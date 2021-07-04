#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if ((i + 1) * i * 0.5 == n) {
            cout << "YES" << endl;
            goto end;
        }
    }
    cout << "NO" << endl;
end:;
    return 0;
}
