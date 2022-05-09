#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    std::getline(cin, s);

    while (n--) {
        std::getline(cin, s);
        cout << s << endl;
    }

    return 0;
}
