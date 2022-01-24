#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int border[1000005];
std::string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        bool flag = false;
        if (s1.substr(i, s2.size()) == s2) {
            cout << i + 1 << endl;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        bool flag = false;
        for (int j = i; j > 0; j--) {
            if (s2.substr(0, j) == s2.substr(i - j + 1, j)) {
                flag = true;
                cout << j << ' ';
                break;
            }
        }
        if (!flag) cout << 0 << ' ';
    }
    cout << endl;
    return 0;
}
