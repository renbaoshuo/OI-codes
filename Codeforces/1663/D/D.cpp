#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int x;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> s >> x;
    cout << (s == "ABC" && x < 2000 || s == "ARC" && x < 2800 || s == "AGC" && x >= 1200 ? "Yes" : "No") << endl;

    return 0;
}
