#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

std::vector<int> a;

int n, t;
long long x;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> x >> s;
    std::reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == 'U') {
            t++;
            c = ' ';
        } else if (t) {
            t--;
            c = ' ';
        }
    }
    while (t--) x >>= 1;
    std::reverse(s.begin(), s.end());
    for (char c : s) {
        if (c == 'L') {
            x <<= 1;
        } else if (c == 'R') {
            x <<= 1;
            x |= 1;
        }
    }
    cout << x << endl;
    return 0;
}
