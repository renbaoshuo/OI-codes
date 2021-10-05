#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    cout << n << endl
         << n / 100 << " nota(s) de R$ 100,00" << endl
         << (n %= 100) / 50 << " nota(s) de R$ 50,00" << endl
         << (n %= 50) / 20 << " nota(s) de R$ 20,00" << endl
         << (n %= 20) / 10 << " nota(s) de R$ 10,00" << endl
         << (n %= 10) / 5 << " nota(s) de R$ 5,00" << endl
         << (n %= 5) / 2 << " nota(s) de R$ 2,00" << endl
         << n % 2 << " nota(s) de R$ 1,00" << endl;
    return 0;
}
