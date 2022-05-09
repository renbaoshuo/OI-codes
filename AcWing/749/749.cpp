#include <bits/stdc++.h>

using namespace std;

int main() {
    char op;
    cin >> op;
    double x, sum = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i < 5 && j > i && j <= 10 - i) sum += x;
        }
    }
    cout << fixed << setprecision(1) << sum / (op == 'S' ? 1 : 30) << endl;

    return 0;
}
