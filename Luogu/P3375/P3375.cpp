#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int next[N], f[N];
std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    next[0] = -1;

    for (int i = 1, j = -1; i < s2.size(); i++) {
        while (~j && s2[i] != s2[j + 1]) j = next[j];
        if (s2[i] == s2[j + 1]) j++;
        next[i] = j;
    }

    for (int i = 0, j = -1; i < s1.size(); i++) {
        while (~j && (j == s2.size() || s1[i] != s2[j + 1])) j = next[j];
        if (s1[i] == s2[j + 1]) j++;
        if (j + 1 == s2.size()) {
            cout << i - j + 1 << endl;
            f[i] = j;
        }
    }

    for (int i = 0; i < s2.size(); i++) {
        cout << next[i] + 1 << ' ';
    }

    cout << endl;

    return 0;
}
