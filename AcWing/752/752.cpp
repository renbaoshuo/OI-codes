#include <bits/stdc++.h>

using namespace std;

int main() {
    char op;
    double sum = 0, x;
    cin >> op;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i < j && i + j >= 12) sum += x;
        }
    }
    cout << fixed << setprecision(1) << sum / (op == 'S' ? 1 : 30) << endl;
    return 0;
}
