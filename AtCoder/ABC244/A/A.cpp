#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int n;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    cout << *s.rbegin() << endl;
    return 0;
}
