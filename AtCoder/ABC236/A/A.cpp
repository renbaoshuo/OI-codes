#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    std::string s;
    int a, b;
    cin >> s >> a >> b;
    char c = s[a - 1];
    s[a - 1] = s[b - 1];
    s[b - 1] = c;
    cout << s << endl;
    return 0;
}
