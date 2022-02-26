#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int a[15];

int main() {
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << a[a[a[0]]] << endl;
    return 0;
}
