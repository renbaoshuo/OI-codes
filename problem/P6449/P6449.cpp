#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, m, z = 3;
    cin >> d >> m;
    for (int i = 1; i < m; i++) {
        int n = 30;
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            n = 31;
        }
        else if (i == 2) {
            n = 28;
        }
        for (int j = 1; j <= n; j++) {
            z++;
            if (z == 8) {
                z = 1;
            }
        }
    }
    for (int i = 1; i <= d; i++) {
        z++;
        if (z == 8) {
            z = 1;
        }
    }
    string ans[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << ans[z] << endl;
    return 0;
}
