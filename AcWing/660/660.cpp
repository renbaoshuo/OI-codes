#include <bits/stdc++.h>

using namespace std;

double price[] = {0.00, 4.00, 4.50, 5.00, 2.00, 1.50};

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Total: R$ " << fixed << setprecision(2) << price[x] * y << endl;
    return 0;
}
