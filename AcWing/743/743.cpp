#include <bits/stdc++.h>

using namespace std;

int main() {
    int l;
    cin >> l;
    char op;
    cin >> op;
    double x, sum = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i == l) sum += x;
        }
    }
    cout << fixed << setprecision(1) << sum / (op == 'S' ? 1 : 12) << endl;
    return 0;
}
