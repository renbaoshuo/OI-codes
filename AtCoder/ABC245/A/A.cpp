#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int a, b, c, d;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    cout << (a == c ? b <= d ? "Takahashi" : "Aoki" : a < c ? "Takahashi"
                                                            : "Aoki")
         << endl;

    return 0;
}
