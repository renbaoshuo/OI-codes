#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

int a, b, c,
    f[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
bool flag = false;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    do {
        int aa = f[0] * 100 + f[1] * 10 + f[2],
            bb = f[3] * 100 + f[4] * 10 + f[5],
            cc = f[6] * 100 + f[7] * 10 + f[8];
        if (aa * b == bb && aa * c == cc || aa == a && bb == b && cc == c) {
            flag = true;
            cout << aa << ' ' << bb << ' ' << cc << endl;
        }
    } while (std::next_permutation(f, f + 9));
    if (!flag) {
        cout << "No!!!" << endl;
    }
    return 0;
}
