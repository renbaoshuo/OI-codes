#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    double sum = 0.00, t;
    cin >> c;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> t;
            if (j > i) sum += t;
        }
    }
    if (c == 'S')
        cout << fixed << setprecision(1) << sum;
    else
        cout << fixed << setprecision(1) << sum / 66;
    return 0;
}
