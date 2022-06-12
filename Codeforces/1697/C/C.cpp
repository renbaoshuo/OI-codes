#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int q, n;
std::string s, t;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;

    while (q--) {
        cin >> n >> s >> t;

        s = ' ' + s;
        t = ' ' + t;

        int b = 1, c = 1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            b = std::max(b, i);
            c = std::max(c, i);

            if (s[i] == 'a' && t[i] == 'c' || s[i] == 'c' && t[i] == 'a' || s[i] == 'c' && t[i] == 'b' || s[i] == 'c' && t[i] == 'a') {
                flag = false;

                break;
            }

            if (s[i] == t[i]) continue;

            if (s[i] == 'a' && t[i] == 'b') {
                while (s[b] != 'b' && s[b] == 'a' && b + 1 <= n) b++;
                std::swap(s[i], s[b]);
            }

            if (s[i] == 'b' && t[i] == 'c') {
                while (s[c] != 'c' && s[c] == 'b' && c + 1 <= n) c++;
                std::swap(s[i], s[c]);
            }

            if (s[i] != t[i]) {
                flag = false;

                break;
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}
