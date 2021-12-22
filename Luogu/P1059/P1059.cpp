#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int n, x;
std::vector<int> a;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;
    for (int i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
