#include "coin.h"

using std::cin;
using std::cout;
using std::endl;

int n, c[105], ans;

int main() {
    n = getn();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 1000; j++) {
            c[i] += !!query(i);
        }
    }
    ans = 1;
    for (int i = 2; i <= n; i++) {
        if (c[i] <= c[ans]) ans = i;
    }
    submit(ans);
    return 0;
}
