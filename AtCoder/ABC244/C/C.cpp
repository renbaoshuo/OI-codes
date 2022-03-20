#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 2005;

int n, x;
bool tag[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    do {
        tag[x] = true;
        int t = 0;
        while (tag[++t] && t <= 2 * n + 1) {}
        tag[t] = true;
        cout << t << endl;
    } while (cin >> x, x);
    return 0;
}
