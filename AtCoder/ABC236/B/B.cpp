#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;

int n, a;
std::map<int, int> map;

int main() {
    cin >> n;
    for (int i = 1; i < n * 4; i++) {
        cin >> a;
        map[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (map[i] == 3) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
