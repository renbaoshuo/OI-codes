#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> s;
    std::sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
