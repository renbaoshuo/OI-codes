#include <bits/stdc++.h>

using namespace std;

int a;

int main() {
    cin >> a;
    cout << fixed << setprecision(1) << (a > 150 ? 0.4463 * 150 + (a > 400 ? 0.4663 * 250 + 0.5663 * (a - 400) : 0.4663 * (a - 150)) : 0.4463 * a) << endl;
    return 0;
}
