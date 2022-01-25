#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 1000005;

int f[N], next[N];
std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    next[0] = -1;
    for (int i = 1, j = -1; i < s2.size(); i++) {
        while (j != -1 && s2[i] != s2[j + 1]) j = next[j];
        if (s2[i] == s2[j + 1]) j++;
        next[i] = j;
    }
    for (int i = 0, j = -1; i < s1.size(); i++) {
        while (j != -1 && (j == s2.size() || s1[i] != s2[j + 1])) j = next[j];
        if (s1[i] == s2[j + 1]) j++;
        if (j == s2.size() - 1) {
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
