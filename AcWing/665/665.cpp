#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    cout << (a % b == 0 || b % a == 0 ? "Sao Multiplos" : "Nao sao Multiplos") << endl;
    return 0;
}
