#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int t, n, next[N];
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> n, n) {
        cout << "Test case #" << ++t << endl;

        cin >> s;

        s = ' ' + s;

        next[1] = 0;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j++;
            next[i] = j;
        }

        for (int i = 2; i <= n; i++) {
            int len = i - next[i];
            if (i % len == 0 && i / len > 1) {
                cout << i << ' ' << i / len << endl;
            }
        }

        cout << endl;
    }

    return 0;
}
