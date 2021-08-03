#include <bits/stdc++.h>

using namespace std;

int main() {
    char op;
    double x, sum = 0;
    cin >> op;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (j < i) sum += x;
        }
    }
    cout << fixed << setprecision(1) << sum / (op == 'S' ? 1 : 66) << endl;
    return 0;
}
