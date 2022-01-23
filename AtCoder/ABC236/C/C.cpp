#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int n, m;
std::string s[100005], a;
std::map<std::string, bool> map;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a;
        map[a] = true;
    }
    for (int i = 1; i <= n; i++) {
        cout << (map[s[i]] ? "Yes" : "No") << endl;
    }
    return 0;
}
