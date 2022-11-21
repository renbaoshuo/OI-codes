#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    std::vector<std::string> v(n);

    for (auto& s : v) cin >> s;

    std::sort(v.begin(), v.end(), [&](const std::string& lhs, const std::string& rhs) -> bool {
        return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
    });

    for (auto& s : v) cout << s << endl;

    return 0;
}
