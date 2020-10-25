#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    std::getline(cin, s);
    cout << s.size() << endl;

    return 0;
}
