#include <bits/stdc++.h>

using namespace std;

int main() {
    char op;
    cin >> op;
    double x, sum = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i < 11 - j) sum += x;
        }
    }
    cout << fixed << setprecision(1) << sum / (op == 'S' ? 1 : 66) << endl;
    return 0;
}
