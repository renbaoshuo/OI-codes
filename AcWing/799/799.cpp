#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

int n, a[100005], s[100005], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1, j = 1; i <= n; i++) {
        s[a[i]]++;
        while (s[a[i]] > 1) s[a[j++]]--;
        ans = std::max(ans, i - j + 1);
    }
    cout << ans << endl;
    return 0;
}
