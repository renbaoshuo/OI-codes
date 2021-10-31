#include <bits/stdc++.h>

using namespace std;

int a, b, c, f[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    do {
        a = f[0] * 100 + f[1] * 10 + f[2];
        b = f[3] * 100 + f[4] * 10 + f[5];
        c = f[6] * 100 + f[7] * 10 + f[8];
        if (a * 3 == c && b * 3 == c * 2) {
            cout << a << ' ' << b << ' ' << c << endl;
        }
    } while (next_permutation(f, f + 9));
    return 0;
}
