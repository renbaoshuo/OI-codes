#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n / 365 << " ano(s)" << endl;
    cout << n % 365 / 30 << " mes(es)" << endl;
    cout << n % 365 % 30 << " dia(s)" << endl;
    return 0;
}
