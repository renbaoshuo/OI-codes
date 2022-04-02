#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, x, sum;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> x;
        sum += x;
    }
    cout << sum << endl;

    return 0;
}
