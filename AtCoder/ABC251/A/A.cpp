#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> s;
    for (int i = 0; i < 6; i++) {
        cout << s[i % s.size()];
    }
    cout << endl;

    return 0;
}
