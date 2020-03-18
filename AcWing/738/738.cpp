#include <bits/stdc++.h>

using namespace std;

int main() {
    int v;
    cin >> v;

    for (int i = 0, x = v; i < 10; i++, x *= 2) {
        printf("N[%d] = %d\n", i, x);
    }

    return 0;
}
