#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n >> s;

        s = ' ' + s;

        int mid = n & 1 ? n / 2 : n / 2 - 1;
        int ans = 2 - (n & 1);

        for (int i = mid; i && s[i] == s[i + 1]; i--) ans += 2;

        cout << ans << endl;
    }

    return 0;
}
