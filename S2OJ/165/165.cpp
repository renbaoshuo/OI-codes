#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int nxt[1000005];
std::string s, p;

int main() {
    cin >> s >> p;
    nxt[0] = -1;
    for (int i = 1, j = -1; i < p.size(); i++) {
        while (j >= 0 && p[j + 1] != p[i]) j = nxt[j];
        if (p[j + 1] == p[i]) j++;
        nxt[i] = j;
    }
    for (int i = 0, j = -1; i < s.size(); i++) {
        while (j != -1 && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == p.size() - 1) {
            cout << i - j + 1 << endl;
            j = nxt[j];
        }
    }
    return 0;
}
