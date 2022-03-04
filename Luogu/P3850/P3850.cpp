#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, q, x, book;
std::vector<int> a;
std::string s, books[100205];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        books[++book] = s;
        a.push_back(book);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s >> x;
        books[++book] = s;
        a.insert(a.begin() + x, book);
    }
    cin >> q;
    while (q--) {
        cin >> x;
        cout << books[a[x]] << endl;
    }
    return 0;
}
