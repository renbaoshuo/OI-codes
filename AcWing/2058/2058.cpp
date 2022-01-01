#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string base2, base3;
std::map<int, bool> m;

int base2ToBase10(std::string s) {
    int res = 0;
    for (int i = s.size() - 1, k = 1; i >= 0; i--, k *= 2) {
        res += k * (s[i] - '0');
    }
    return res;
}

int base3ToBase10(std::string s) {
    int res = 0;
    for (int i = s.size() - 1, k = 1; i >= 0; i--, k *= 3) {
        res += k * (s[i] - '0');
    }
    return res;
}

int main() {
    cin >> base2 >> base3;
    for (int i = 0; i < base2.size(); i++) {
        for (int j = 0; j < 2; j++) {
            base2[i] = (base2[i] - '0' + 1) % 2 + '0';
            m[base2ToBase10(base2)] = true;
        }
    }
    for (int i = 0; i < base3.size(); i++) {
        for (int j = 0; j < 3; j++) {
            base3[i] = (base3[i] - '0' + 1) % 3 + '0';
            if (m.count(base3ToBase10(base3))) {
                cout << base3ToBase10(base3) << endl;
                exit(0);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
