#include <bits/stdc++.h>

using namespace std;

int main() {
    string ans[5] = {".", ".", "#", ".", "."};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ((i + 1) % 3 == 0) {
            ans[0] += ".*..";
            ans[1] += "*.*.";
            ans[2] += (string) "." + s[i] + ".*";
            ans[3] += "*.*.";
            ans[4] += ".*..";
        } else {
            ans[0] += ".#..";
            ans[1] += "#.#.";
            if ((i + 1) % 3 == 2 && i + 1 != s.size()) {
                ans[2] += (string) "." + s[i] + ".*";
            } else {
                ans[2] += (string) "." + s[i] + ".#";
            }
            ans[3] += "#.#.";
            ans[4] += ".#..";
        }
    }
    cout << ans[0] << endl
         << ans[1] << endl
         << ans[2] << endl
         << ans[3] << endl
         << ans[4] << endl;
    return 0;
}
