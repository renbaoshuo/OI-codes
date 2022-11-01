#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string a, b;
    std::unordered_map<char, int> map;

    cin >> a >> b;

    for (char c : b) map[c]++;

    cout << (a.size() + 1) * (b.size() + 1) - std::accumulate(a.begin(), a.end(), 0ll, [&](long long lhs, char rhs) -> long long { return lhs + map[rhs]; }) << endl;

    return 0;
}
