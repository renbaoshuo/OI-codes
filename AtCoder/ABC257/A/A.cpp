#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, k;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    cout << char('A' + (k - 1) / n) << endl;

    return 0;
}
