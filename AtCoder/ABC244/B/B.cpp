#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 4;
const int to[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int n, x, y, d;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    for (char c : s) {
        if (c == 'S') {
            x += to[d][0];
            y += to[d][1];
        } else {
            d = ++d % mod;
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
