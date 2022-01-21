#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t;
long long n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        if (floor(log2(n)) == log2(n) || floor(log2(n / 3.0)) == log2(n / 3.0)) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}
