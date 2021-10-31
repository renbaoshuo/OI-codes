#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;
    cin >> x;
    cout << fixed << setprecision(0) << (x < 0 ? ceil(x) : floor(x)) << endl;
    return 0;
}
