#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

const int N = 1000005;

int n, m, a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int min = std::numeric_limits<int>::max(),
        max = std::numeric_limits<int>::min();
    for (int i = 1; i <= n; i++) {
        min = std::min(min, std::max(a[i], b[i]));
        max = std::max(max, std::min(a[i], b[i]));
    }
    cout << max - min << endl;
    return 0;
}
