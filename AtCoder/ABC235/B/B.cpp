#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n, h, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        if (h <= ans) {
            break;
        } else {
            ans = h;
        }
    }
    cout << ans << endl;
    return 0;
}
