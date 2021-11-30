#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int max, min;
std::string s;
std::map<char, int> map;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    max = std::numeric_limits<int>::min();
    min = std::numeric_limits<int>::max();
    cin >> s;
    for (char c : s) {
        map[c]++;
    }
    for (auto c : map) {
        max = std::max(max, c.second);
        min = std::min(min, c.second);
    }
    if (isPrime(max - min)) {
        cout << "Lucky Word" << endl
             << max - min << endl;
    } else {
        cout << "No Answer" << endl
             << 0 << endl;
    }
    return 0;
}
